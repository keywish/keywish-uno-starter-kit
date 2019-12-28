#include "Protocol.h"
#include "ProtocolParser.h"
#include <SoftwareSerial.h>


#if ARDUINO > 10609
ProtocolParser::ProtocolParser(byte startcode = PROTOCOL_START_CODE, byte endcode = PROTOCOL_END_CODE)
#else 
ProtocolParser::ProtocolParser(byte startcode , byte endcode )
#endif
{
    m_recv_flag = false;
    m_send_success = false;
    m_StartCode = startcode;
    m_EndCode = endcode;
    m_pHeader = buffer;        // protocol header
    protocol_data_len = 0;     // protocol->data length
    m_PackageLength = 0;       // recevie all package length
    m_CheckSum = 0x0000;
    m_RecvDataIndex = 0;
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = 0;
    }
}

ProtocolParser::~ProtocolParser()
{
    m_pHeader = NULL;
}
#if ARDUINO > 10609
bool ProtocolParser::ParserPackage(char *data = NULL)
#else 
bool ProtocolParser::ParserPackage(char *data)
#endif
{
    if (m_recv_flag) {
        m_recv_flag = false;
        if( data != NULL) {
            m_pHeader = (byte *)data;
        } else {
            m_pHeader = buffer;
        }
        unsigned short int check_sum = 0;
        recv->start_code = buffer[0];
        recv->len = buffer[1];
        for (int i = 1; i < m_PackageLength - 3; i++) {
            check_sum += buffer[i];
        }
        if ((check_sum & 0xFFFF) != GetCheckSum()) {
            //DEBUG_ERR("check sum error \n");
            for (int i = 0; i < m_PackageLength; i++) {
                // DEBUG_LOG(DEBUG_LEVEL_ERR, "0x%x ", buffer[i]);
            }
        return false ;
	    }
        recv->function = buffer[4];
        recv->data = &buffer[5];
        protocol_data_len = m_PackageLength - 8;
        recv->end_code = buffer[m_RecvDataIndex];
        // DEBUG_LOG(DEBUG_LEVEL_INFO, "\nRecevPackage end \n");
        return true;
	}
    return false;
}

extern SoftwareSerial mySerial;
bool ProtocolParser::RecevData(void)
{
   // // DEBUG_LOG(DEBUG_LEVEL_INFO, "RecevData start \n");

    static bool avilable = false;
    byte preRecvLen = 0;
    byte dat;

    while (mySerial.available() > 0) {   
        dat =mySerial.read();
        // // DEBUG_LOG(DEBUG_LEVEL_INFO, "\n");
        Serial.println(dat, HEX);
        delay(2);
        if (avilable == false && dat == m_StartCode) {
              for (int i = 0; i < BUFFER_SIZE; i++) {
                 buffer[i] = 0;
             }
            preRecvLen = 0;
            m_pHeader = buffer;
            *m_pHeader++ = dat;
            m_RecvDataIndex = 0;
            avilable = true;
            // Serial.println(dat, HEX);
            // DEBUG_LOG(DEBUG_LEVEL_INFO, "aviable\n");
            continue;
        }
        if (avilable) {
            if (dat == m_EndCode && preRecvLen == m_RecvDataIndex) {
                avilable = false;
                *m_pHeader = dat;
                m_RecvDataIndex++;
                m_PackageLength = m_RecvDataIndex + 1;
                m_recv_flag = true;
                protocol_data_len = m_PackageLength - 8;
                //DEBUG_LOG(//DEBUG_LEVEL_INFO, "RecevData end \n");
                return true;
           } else {
                //Serial.println(dat, HEX);
                *m_pHeader++ = dat;
                m_RecvDataIndex++;
                if (m_RecvDataIndex == 1) {
                   // DEBUG_LOG(DEBUG_LEVEL_INFO, "m_RecvDataIndex %d\n", m_RecvDataIndex);
                   preRecvLen = dat;
                }
                if ( preRecvLen > BUFFER_SIZE || (m_RecvDataIndex > preRecvLen && preRecvLen != 0)) {
                        for (int i = 0; i < BUFFER_SIZE; i++) {
                            // DEBUG_LOG(DEBUG_LEVEL_INFO, "%x ", buffer[i]);
                        }
                        preRecvLen = 0;
                        m_pHeader = buffer;
                        avilable = false;
                        m_recv_flag = false;
                        Serial.println("preRecvLen\n");
                        return false;
                }

                if (m_RecvDataIndex >= BUFFER_SIZE - 1) {
                    for (int i = 0; i < BUFFER_SIZE; i++) {
                        // DEBUG_LOG(DEBUG_LEVEL_ERR, "%x ", buffer[i]);
                    }
                    Serial.println("buffer is error\n");
                    preRecvLen = 0;
                    m_pHeader = buffer;
                    avilable = false;
                    m_recv_flag = false;
                    return false;
                 }
            }
        }
    }
    return avilable;
}

bool ProtocolParser::RecevData(char *data, size_t len)
{
    // DEBUG_LOG(DEBUG_LEVEL_INFO, "RecevData start \n");
    bool avilable = false;
    if (data == NULL || len > BUFFER_SIZE)
    {
        //DEBUG_ERR("len > BUFFER_SIZE \n");
        return false;
    }
    m_PackageLength = 0;
    m_pHeader = buffer;
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = 0;
    }
    while (len--) {
        if(!avilable && *data == m_StartCode)  {
            avilable = true;
        }
        if (avilable) {
            if ((*m_pHeader = *data) == m_EndCode) {
                m_PackageLength++;
                // DEBUG_LOG(DEBUG_LEVEL_INFO, "%x", *m_pHeader);
                break;
            }
            // DEBUG_LOG(DEBUG_LEVEL_INFO, "%x", *m_pHeader);
            m_pHeader++;
            m_RecvDataIndex++;
        }
        data++;
    }
    if (avilable)
    m_PackageLength =  m_RecvDataIndex + 1;
    // DEBUG_LOG(DEBUG_LEVEL_INFO, "\nRecevPackage done\n");
    return true;
}


E_TYPE ProtocolParser::GetRobotType()
{
    return (E_TYPE)recv->type;
}

uint8_t ProtocolParser::GetRobotAddr()
{
    return recv->addr;
}

E_CONTOROL_FUNC ProtocolParser::GetRobotControlFun()
{
    return (E_CONTOROL_FUNC)recv->function;
}

int ProtocolParser::GetRobotSpeed()
{
    if (recv->function == E_ROBOT_CONTROL_SPEED ) {
        return (int)(*(recv->data));
    } else {
        return 0;
    }
}

int ProtocolParser::GetRobotDegree()
{
    if (recv->function == E_ROBOT_CONTROL_DIRECTION ) {
        return ((int)(*(recv->data)<< 8) | (int)(*(recv->data+1)));
    } else {
        return 0;
    }
}

byte* ProtocolParser::GetPianoSing()
{
    if (recv->function == E_BUZZER) {
        return (recv->data);
    } else {
        return 0;
    }
}

long ProtocolParser::GetRgbValue(void)
{
    if (recv->function == E_LED) {
        long value = ((long)(*(recv->data+2))<< 16 | (long)(*(recv->data+1))<< 8 | (long)(*(recv->data)));
        return value;
    } else {
        return 0;
    }
}

uint8_t ProtocolParser::GetProtocolDataLength()
{
    return protocol_data_len;
}

uint8_t ProtocolParser::GetPackageLength()
{
    return m_PackageLength;
}

byte ProtocolParser::GetControlMode()
{
    if (((E_CONTOROL_FUNC)recv->function) == E_CONTROL_MODE) {
        return (byte)(*(recv->data));
    } else {
        return 0;
    }
}

uint16_t ProtocolParser::GetCheckSum(void)
{
    return ((buffer[m_PackageLength - 3] << 8 ) |  buffer[m_PackageLength - 2]);
}

// len : protocol data length
bool ProtocolParser::SendPackage(ST_PROTOCOL *send_dat,int len)
{
    if( send_dat == NULL || len > BUFFER_SIZE) {
        //DEBUG_ERR("SendPackage error");
        return false;
    }
    unsigned short checksum = 0;
    byte *p_data = &buffer[5];
    protocol_data_len = len;
    buffer[0] = send_dat->start_code;
    buffer[1] = send_dat->len;
    buffer[2] = send_dat->type;
    buffer[3] = send_dat->addr;
    buffer[4] = send_dat->function;
    checksum = buffer[1] + buffer[2] + buffer[3] + buffer[4];

  //  Serial.println(*send_dat->data);
   // Serial.println(*(send_dat->data + 1 ));
    for(int i = 0; i < len; i++) {
       *(p_data+i) = *(send_dat->data + i);
    //   Serial.println(*(p_data+i) );
       checksum += *(send_dat->data + i);
    }
    *(p_data + len) = (checksum >> 8) & 0xFF;
    *(p_data + len + 1) = checksum & 0xFF;
    *(p_data + len + 2) = send_dat->end_code;

   mySerial.write(buffer,len+8);
   mySerial.flush();
    delay(100);
    return true;
}
