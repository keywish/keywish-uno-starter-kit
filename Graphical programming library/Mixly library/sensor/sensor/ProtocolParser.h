#ifndef   _PROTOCOLPARSER_H_
#define   _PROTOCOLPARSER_H_
#include "Arduino.h"
#include "Protocol.h"
#include <stdint.h>



#define BUFFER_SIZE 24

class ProtocolParser
{
public:
    ProtocolParser(byte header = PROTOCOL_START_CODE, byte end = PROTOCOL_END_CODE);
    ~ProtocolParser();
    bool RecevData(char *data, size_t len);
    bool RecevData(void);
    bool ParserPackage(char *data = NULL);
    E_TYPE GetRobotType();
    uint8_t GetRobotAddr();
    E_CONTOROL_FUNC GetRobotControlFun();
    int GetRobotSpeed();
    int GetRobotDegree();
    byte *GetPianoSing();
    long GetRgbValue();
    bool SendPackage(ST_PROTOCOL *send_dat,int len);
    byte GetControlMode();

private:
    byte buffer[BUFFER_SIZE];
    byte m_StartCode, m_EndCode;
    ST_PROTOCOL *recv;
    uint8_t protocol_data_len;
    bool m_recv_flag, m_send_success;   // recevive flag
    byte *m_pHeader;                    // protocol header
    uint8_t m_PackageLength;            // recevie package length
    uint16_t m_CheckSum;
    uint8_t m_RecvDataIndex;            // get recevie data index
    char GetHeader(size_t index);
    uint8_t GetProtocolDataLength();
    uint8_t GetPackageLength();
    uint16_t GetCheckSum();             // get package check sum
};

#endif // _PROTOCOLPARSER_H_
