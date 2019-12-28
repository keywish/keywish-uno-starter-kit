'use strict';

goog.provide('Blockly.Blocks.sensor');

goog.require('Blockly.Blocks');


//var KW_LEDPRINT = [["A","A"],["C","C"],["B","B"],["D","D"],["E","E"],["F","F"],["G","G"],["H","H"],["I","I"],["J","J"],["K","K"],["L","L"],["M","M"],["N","N"],["O","O"],["P","P"],["Q","Q"],["R","R"],["S","S"],["T","T"],["U","U"],["V","V"],["W","W"],["X","X"],["Y","Y"],["Z","Z"]];
var KW_IRKEY=[["1","IR_KEYCODE_1"],["2","IR_KEYCODE_2"],["3","IR_KEYCODE_3"],["4","IR_KEYCODE_4"],["5","IR_KEYCODE_5"],["6","IR_KEYCODE_6"],["7","IR_KEYCODE_7"],["8","IR_KEYCODE_8"],["9","IR_KEYCODE_9"],["0","IR_KEYCODE_0"],["*","IR_KEYCODE_STAR"],["#","IR_KEYCODE_POUND"],[Blockly.KW_IRKEY_UP,"IR_KEYCODE_UP"],[Blockly.KW_IRKEY_DOWN,"IR_KEYCODE_DOWN"],["OK","IR_KEYCODE_OK"],[Blockly.KW_IRKEY_LEFT,"IR_KEYCODE_LEFT"],[Blockly.KW_IRKEY_RIGHT,"IR_KEYCODE_RIGHT"]];
var KW_IRKEY2=[["1","EM_IR_KEYCODE_1"],["2","EM_IR_KEYCODE_2"],["3","EM_IR_KEYCODE_3"],["4","EM_IR_KEYCODE_4"],["5","EM_IR_KEYCODE_5"],["6","EM_IR_KEYCODE_6"],["7","EM_IR_KEYCODE_7"],["8","EM_IR_KEYCODE_8"],["9","EM_IR_KEYCODE_9"],["0","EM_IR_KEYCODE_0"],["A","EM_IR_KEYCODE_A"],["B","EM_IR_KEYCODE_B"],["C","EM_IR_KEYCODE_C"],["D","EM_IR_KEYCODE_D"],["+","EM_IR_KEYCODE_PLUS"],["-","EM_IR_KEYCODE_REDUCE"],[Blockly.KW_IRKEY_UP,"EM_IR_KEYCODE_UP"],[Blockly.KW_IRKEY_DOWN,"EM_IR_KEYCODE_DOWN"],["OK","EM_IR_KEYCODE_OK"],[Blockly.KW_IRKEY_LEFT,"EM_IR_KEYCODE_LEFT"],[Blockly.KW_IRKEY_RIGHT,"EM_IR_KEYCODE_RIGHT"]];
var KW_BLUETOOTHMODES=[[Blockly.KW_BLUETOOTHMODES_RGB,"2"],[Blockly.KW_BLUETOOTHMODES_BUZZER,"3"]];
var KW_MAXIMAGE=[[Blockly.KW_MAXIMAGE_ZERO,"0"],[Blockly.KW_MAXIMAGE_ONE,"1"],[Blockly.KW_MAXIMAGE_TWO,"2"],[Blockly.KW_MAXIMAGE_THREE,"3"],[Blockly.KW_MAXIMAGE_FOUR,"4"],[Blockly.KW_MAXIMAGE_FIVE,"5"],[Blockly.KW_MAXIMAGE_SIX,"6"],[Blockly.KW_MAXIMAGE_SEVEN,"7"],[Blockly.KW_MAXIMAGE_EIGHT,"8"],[Blockly.KW_MAXIMAGE_NINE,"9"],[Blockly.KW_MAXIMAGE_SMILE,"10"],[Blockly.KW_MAXIMAGE_HAPPYOPEN,"11"],[Blockly.KW_MAXIMAGE_HAPPYCLOSED,"12"],[Blockly.KW_MAXIMAGE_HEART,"13"],[Blockly.KW_MAXIMAGE_BIGSURPRISE,"14"],[Blockly.KW_MAXIMAGE_SMALLSURPRISE,"15"],[Blockly.KW_MAXIMAGE_TONGUE,"16"],[Blockly.KW_MAXIMAGE_VAMP1,"17"],[Blockly.KW_MAXIMAGE_VAMP2,"18"],[Blockly.KW_MAXIMAGE_LINEMOUTH,"19"],[Blockly.KW_MAXIMAGE_CONFUSED,"20"],[Blockly.KW_MAXIMAGE_DIAGONAL,"21"],[Blockly.KW_MAXIMAGE_SAD,"22"],[Blockly.KW_MAXIMAGE_SADOPEN,"23"],[Blockly.KW_MAXIMAGE_SADCLOSED,"24"],[Blockly.KW_MAXIMAGE_OKMOUTH,"25"],[Blockly.KW_MAXIMAGE_XMOUTH,"26"],[Blockly.KW_MAXIMAGE_INTTEROGATION,"27"],[Blockly.KW_MAXIMAGE_THUNDER,"28"],[Blockly.KW_MAXIMAGE_CULITO,"29"],[Blockly.KW_MAXIMAGE_ANGRY,"30"]];
var KW_RGBPOSITION=[[Blockly.KW_ALL,"E_RGB_ALL"],[Blockly.KW_RIGHT,"E_RGB_RIGHT"],[Blockly.KW_LEFT,"E_RGB_LEFT"]];
var KE_RGBCOLOR=[[Blockly.KW_RED,"RGB_RED"],[Blockly.KW_GREEN,"RGB_GREEN"],[Blockly.KW_BLUE,"RGB_BLUE"],[Blockly.KW_YELLOW,"RGB_YELLOW"],[Blockly.KW_PURPLE,"RGB_PURPLE"],[Blockly.KW_ORANGE,"RGB_ORANGE"],[Blockly.KW_INDIGO,"RGB_INDIGO"],[Blockly.KW_VIOLET,"RGB_VIOLET"],[Blockly.KW_WHITE,"RGB_WHITE"],[Blockly.KW_BLACK,"0x000000"]];
var KE_RGBSTYLE=[[Blockly.KW_NONE,"E_EFFECT_NONE"],[Blockly.KW_BREATHING,"E_EFFECT_BREATHING"],[Blockly.KW_ROTATE,"E_EFFECT_ROTATE"],[Blockly.KW_FLASH,"E_EFFECT_FLASH"]];
//舵机引脚value 转动角度value
Blockly.Blocks.kw_servo = {
  init: function() {
   this.setColour(100);
	this.appendValueInput("servopin", Number)
        .setCheck(Number)
        .setAlign(Blockly.ALIGN_RIGHT)
		.appendField(Blockly.KW_SERVOPIN)
	this.appendValueInput("servoangle", Number)
        .setCheck(Number)
        .setAlign(Blockly.ALIGN_RIGHT)
        .appendField(Blockly.KW_SERVOANGLE);
    this.setPreviousStatement(true, null);
	this.setInputsInline(true);
    this.setNextStatement(true, null);

  }
};
//初始化7段数码管
Blockly.Blocks.kw_7ledinit = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	      .appendField(Blockly.KW_7LEDINIT);
	this.appendValueInput("pin1", Number)
        .appendField(Blockly.KW_A)
        .setCheck(Number);
this.appendValueInput("pin2", Number)
        .appendField(Blockly.KW_B)
        .setCheck(Number);
this.appendValueInput("pin3", Number)
        .appendField(Blockly.KW_C)
        .setCheck(Number);
this.appendValueInput("pin4", Number)
        .appendField(Blockly.KW_D)
        .setCheck(Number);
this.appendValueInput("pin5", Number)
        .appendField(Blockly.KW_E)
        .setCheck(Number);
this.appendValueInput("pin6", Number)
        .appendField(Blockly.KW_F)
        .setCheck(Number);
this.appendValueInput("pin7", Number)
        .appendField(Blockly.KW_G)
        .setCheck(Number);
this.appendValueInput("pin8", Number)
        .appendField(Blockly.KW_H)
        .setCheck(Number);
			this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
	this.setInputsInline(true);
  }
};
//7段数码管显示数字value
Blockly.Blocks.kw_7leddisplaynum = {
  init: function() {
    this.setColour(100);
	this.appendDummyInput("")
	      .appendField(Blockly.KW_7LEDDISPLAYNUM);
    this.appendValueInput("displaynum", Number)
        .setCheck(Number);
	this.setInputsInline(true);
	this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);

  }
};
//初始化4*7段数码管
Blockly.Blocks.kw_47ledinit = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	      .appendField(Blockly.KW_47LEDINIT);
	this.appendValueInput("Pin1", Number)
        .appendField(Blockly.KW_A)
        .setCheck(Number);
this.appendValueInput("Pin2", Number)
        .appendField(Blockly.KW_B)
        .setCheck(Number);
this.appendValueInput("Pin3", Number)
        .appendField(Blockly.KW_C)
        .setCheck(Number);
this.appendValueInput("Pin4", Number)
        .appendField(Blockly.KW_D)
        .setCheck(Number);
this.appendValueInput("Pin5", Number)
        .appendField(Blockly.KW_E)
        .setCheck(Number);
this.appendValueInput("Pin6", Number)
        .appendField(Blockly.KW_F)
        .setCheck(Number);
this.appendValueInput("Pin7", Number)
        .appendField(Blockly.KW_G)
        .setCheck(Number);
this.appendValueInput("Pin8", Number)
        .appendField(Blockly.KW_H)
        .setCheck(Number);
this.appendValueInput("Pin9", Number)
        .appendField(Blockly.KW_D1)
        .setCheck(Number);
this.appendValueInput("Pin10", Number)
        .appendField(Blockly.KW_D2)
        .setCheck(Number);
this.appendValueInput("Pin11", Number)
        .appendField(Blockly.KW_D3)
        .setCheck(Number);
this.appendValueInput("Pin12", Number)
        .appendField(Blockly.KW_D4)
        .setCheck(Number);
			this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
	this.setInputsInline(true);
  }
};
//4*7段数码管显示
Blockly.Blocks.kw_7ledcountnum = {
  init: function() {
    this.setColour(100);
	this.appendDummyInput("")
	      .appendField(Blockly.KW_7LEDFROM);
    this.appendValueInput("count", Number)
        .setCheck(Number);

	this.setInputsInline(true);
	this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);

  }
};

Blockly.Blocks.kw_7ledcountnumoff = {
  init: function() {
    this.setColour(100);
	this.appendDummyInput("")
	      .appendField(Blockly.KW_7LEDFROMOFF);
   this.setInputsInline(true);
	this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);

  }
};
//超声波测距
Blockly.Blocks.kw_ultrasonicread = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	      .appendField(Blockly.KW_ULTRASONICREAD);
	this.appendValueInput("trigpin", Number)
        .appendField(Blockly.KW_TRIG)
        .setCheck(Number);
this.appendValueInput("echopin", Number)
        .appendField(Blockly.KW_ECHO)
        .setCheck(Number);
			this.setInputsInline(true);
    this.setOutput(true, Number);
	this.setInputsInline(true);
  }
};

//初始化点阵屏
Blockly.Blocks.kw_dianzhen = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	      .appendField(Blockly.KW_INITDIANZHEN);
	this.appendValueInput("din", Number)
        .appendField(Blockly.KW_DIN)
        .setCheck(Number);
this.appendValueInput("cs", Number)
        .appendField(Blockly.KW_CS)
        .setCheck(Number);
this.appendValueInput("clk", Number)
        .appendField(Blockly.KW_CLK)
        .setCheck(Number);
this.appendValueInput("count", Number)
        .appendField(Blockly.KW_COUNT)
        .setCheck(Number);
			this.setInputsInline(true);
     this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
	this.setInputsInline(true);
  }
};
//点阵屏显示 下拉
Blockly.Blocks.kw_dianzhenprint = {
   init: function() {
    this.setColour(100);
    this.appendDummyInput("")
        .appendField(Blockly.KW_MAXIMAGES)
		.appendField(new Blockly.FieldDropdown(KW_MAXIMAGE), "maximage");
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
	this.setInputsInline(true);
  }

};
//串口有蓝牙数据可读
Blockly.Blocks.kw_getbluetooth = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	    .appendField(Blockly.KW_GETBLUETOOTH)
    this.setOutput(true, Boolean);
	this.setInputsInline(true);
  }
};
//串口读取蓝牙数据
Blockly.Blocks.kw_getbluetoothdata = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	    .appendField(Blockly.KW_GETBLUETOOTHDATA)
    this.setOutput(true, Number);
	this.setInputsInline(true);
  }
};

//初始化红外遥控 引脚value
Blockly.Blocks.kw_initir = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	    .appendField(Blockly.KW_INITIR)
	this.appendValueInput("initir", Number)
        .setCheck(Number);
			this.setInputsInline(true);
      this.setPreviousStatement(true, null);
	this.setInputsInline(true);
    this.setNextStatement(true, null);
  }
};
// 普通红外遥控按键（下拉，返回boolean）
Blockly.Blocks.kw_irKeyPress = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
        .appendField(Blockly.KW_IRKEYPRESS)
		.appendField(new Blockly.FieldDropdown(KW_IRKEY), "Irkey")
    this.setOutput(true, Boolean);
    this.setTooltip('');
  }
};
// emakefun红外遥控按键（下拉，返回boolean）
Blockly.Blocks.kw_irKeyPress2 = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
        .appendField(Blockly.KW_IRKEYPRESS2)
		.appendField(new Blockly.FieldDropdown(KW_IRKEY2), "Irkey2")
    this.setOutput(true, Boolean);
    this.setTooltip('');
  }
};
//设置DS3231时钟时间 年月日星期时分秒
Blockly.Blocks.kw_ds3231setdate = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	      .appendField(Blockly.KW_DS3231SETDATE);
	this.appendValueInput("year", Number)
        .appendField(Blockly.KW_DS3231SETDATEYAER)
        .setCheck(Number);
this.appendValueInput("month", Number)
        .appendField(Blockly.KW_DS3231SETDATEMONTH)
        .setCheck(Number);
this.appendValueInput("day", Number)
        .appendField(Blockly.KW_DS3231SETDATEDAY)
        .setCheck(Number);
this.appendValueInput("week", Number)
        .appendField(Blockly.KW_DS3231SETDATEWEEK)
        .setCheck(Number);
this.appendValueInput("hour", Number)
        .appendField(Blockly.KW_DS3231SETDATEHOUR)
        .setCheck(Number);
this.appendValueInput("minute", Number)
        .appendField(Blockly.KW_DS3231SETDATEMINUTE)
        .setCheck(Number);
this.appendValueInput("sencond", Number)
        .appendField(Blockly.KW_DS3231SETDATESECOND)
        .setCheck(Number);
			this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
	this.setInputsInline(true);
  }
};
//da3231时钟获取时间
Blockly.Blocks.kw_ds3231gettime = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	    .appendField(Blockly.KW_DA3231GETTIME)
      this.setPreviousStatement(true, null);
	this.setInputsInline(true);
    this.setNextStatement(true, null);
  }
};
//da3231时钟读取年月日
Blockly.Blocks.kw_ds3231readyear = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	    .appendField(Blockly.KW_DA3231READYEAR)
    this.setOutput(true, Number);
	this.setInputsInline(true);
  }
};
//da3231时钟读取时分秒温度
Blockly.Blocks.kw_ds3231readhour = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	    .appendField(Blockly.KW_DS3231READHOUR)
    this.setOutput(true, Number);
	this.setInputsInline(true);
  }
};
//设置矩阵键盘引脚
Blockly.Blocks.kw_keypad = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	      .appendField(Blockly.KW_DEYPAD);
	this.appendValueInput("row_1", Number)
        .appendField(Blockly.KW_DEYPADROW1)
        .setCheck(Number);
this.appendValueInput("row_2", Number)
        .appendField(Blockly.KW_DEYPADROW2)
        .setCheck(Number);
this.appendValueInput("row_3", Number)
        .appendField(Blockly.KW_DEYPADROW3)
        .setCheck(Number);
this.appendValueInput("row_4", Number)
        .appendField(Blockly.KW_DEYPADROW4)
        .setCheck(Number);
this.appendValueInput("COL_1", Number)
        .appendField(Blockly.KW_DEYPADCOL1)
        .setCheck(Number);
this.appendValueInput("COL_2", Number)
        .appendField(Blockly.KW_DEYPADCOL2)
        .setCheck(Number);
this.appendValueInput("COL_3", Number)
        .appendField(Blockly.KW_DEYPADCOL3)
        .setCheck(Number);
this.appendValueInput("COL_4", Number)
        .appendField(Blockly.KW_DEYPADCOL4)
        .setCheck(Number);
			this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
	this.setInputsInline(true);
  }
};
//获取矩阵键盘值
Blockly.Blocks.kw_getkeypad = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	    .appendField(Blockly.KW_GETKEYPAD)
      this.setPreviousStatement(true, null);
	this.setInputsInline(true);
    this.setNextStatement(true, null);
  }
};
//矩阵键盘按键被按下
Blockly.Blocks.kw_keypadpressed = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	    .appendField(Blockly.KW_KEYPADPRESED)
    this.setOutput(true, Boolean);
	this.setInputsInline(true);
  }
};
//矩阵键盘按键值
Blockly.Blocks.kw_keypadvalue = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	    .appendField(Blockly.KW_KEYPADVALUE)
    this.setOutput(true, Number);
	this.setInputsInline(true);
  }
};
//接收蓝牙数据
Blockly.Blocks.kw_getbluetoothvalue = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	    .appendField(Blockly.KW_GETBLUETOOTHVALUE)
      this.setPreviousStatement(true, null);
	this.setInputsInline(true);
    this.setNextStatement(true, null);
  }
};
//接收到了蓝牙数据
Blockly.Blocks.kw_dogetbluetoothvalue = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	    .appendField(Blockly.KW_DOGETBLUETOOTHVALUE)
    this.setOutput(true, Boolean);
	this.setInputsInline(true);
  }
};
//蓝牙模式 下拉，返回boolean
Blockly.Blocks.kw_bluetoothmode = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	    .appendField(Blockly.KW_BLUETOOTHMODE)
		.appendField(new Blockly.FieldDropdown(KW_BLUETOOTHMODES), "Bluetoothmodes")
    this.setOutput(true, Boolean);
	this.setTooltip('');
  }
};
//蓝牙获取RGB值
Blockly.Blocks.kw_bluetoothgetrgbvalue = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	    .appendField(Blockly.KW_BLUETOOTHGETRGBVALUE)
   this.setOutput(true, Number);
	this.setInputsInline(true);
  }
};
//蓝牙调光
Blockly.Blocks.kw_bluetoothsetrgb = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	    .appendField(Blockly.KW_BLUETOOTHSETRGB)
      this.setPreviousStatement(true, null);
	this.setInputsInline(true);
    this.setNextStatement(true, null);
  }
};
//蓝牙钢琴
Blockly.Blocks.kw_bluetoothsetbuzzer = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	    .appendField(Blockly.KW_BLUETOOTHSETBUZZER)
      this.setPreviousStatement(true, null);
	this.setInputsInline(true);
    this.setNextStatement(true, null);
  }
};
//蜂鸣器引脚value
Blockly.Blocks.kw_buzzerpin = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	    .appendField(Blockly.KW_BUZZERPIN)
	this.appendValueInput("buzzerpin", Number)
        .setCheck(Number);
			this.setInputsInline(true);
      this.setPreviousStatement(true, null);
	this.setInputsInline(true);
    this.setNextStatement(true, null);
  }
};
//iic数码管

Blockly.Blocks.kw_iicinit = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	    .appendField(Blockly.KW_IICINIT)
		this.appendDummyInput("")
	    .appendField(Blockly.KW_IICTUBECLK)
	this.appendValueInput("clk", Number)
        .setCheck(Number);
	this.appendDummyInput("")
	    .appendField(Blockly.KW_IICTUBEDIO)
	this.appendValueInput("dio", Number)
        .setCheck(Number);
			this.setInputsInline(true);
      this.setPreviousStatement(true, null);
	this.setInputsInline(true);
    this.setNextStatement(true, null);
  }
};

Blockly.Blocks.kw_iicdisplaynum = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	    .appendField(Blockly.KW_IICDISPLAYNUM)
		this.appendDummyInput("")
	    //.appendField(Blockly.KW_IICTUBENUM1)
	this.appendValueInput("num1", Number)
        .setCheck(Number);
	this.appendDummyInput("")
	    //.appendField(Blockly.KW_IICTUBENUM2)
	this.appendValueInput("num2", Number)
        .setCheck(Number);
		this.appendDummyInput("")
	    //.appendField(Blockly.KW_IICTUBENUM3)
	this.appendValueInput("num3", Number)
        .setCheck(Number);
	this.appendDummyInput("")
	    //.appendField(Blockly.KW_IICTUBENUM4)
	this.appendValueInput("num4", Number)
        .setCheck(Number);
			this.setInputsInline(true);
      this.setPreviousStatement(true, null);
	this.setInputsInline(true);
    this.setNextStatement(true, null);
  }
};
Blockly.Blocks.kw_iictube = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	    .appendField(Blockly.KW_IICTUBE)
		this.appendDummyInput("")
	    .appendField(Blockly.KW_IICTUBEHOUR)
	this.appendValueInput("hours", Number)
        .setCheck(Number);
	this.appendDummyInput("")
	    .appendField(Blockly.KW_IICTUBEMINUTE)
	this.appendValueInput("minutes", Number)
        .setCheck(Number);
			this.setInputsInline(true);
      this.setPreviousStatement(true, null);
	this.setInputsInline(true);
    this.setNextStatement(true, null);
  }
};
Blockly.Blocks.kw_stepper = {
 init: function() {
	 this.setColour(100);
     this.appendDummyInput("")
	     .appendField(Blockly.KW_STEPPER)
		  this.appendValueInput("ste", Number)
		.appendField(Blockly.KW_STE)
        .setCheck(Number);
     this.appendValueInput("in1", Number)
	   .appendField(Blockly.KW_IN1)
        .setCheck(Number);
   this.appendValueInput("in2", Number)
		.appendField(Blockly.KW_IN2)
        .setCheck(Number);
		     this.appendValueInput("in3", Number)
	   .appendField(Blockly.KW_IN3)
        .setCheck(Number);
   this.appendValueInput("in4", Number)
		.appendField(Blockly.KW_IN4)
        .setCheck(Number);
    this.setPreviousStatement(true, null);
	this.setInputsInline(true);
    this.setNextStatement(true, null);
  }
};

Blockly.Blocks.kw_stepperspeed = {
 init: function() {
	 this.setColour(100);
     this.appendDummyInput("")
	     .appendField(Blockly.KW_STEPPER1)
     this.appendValueInput("speed1", Number)
	   .appendField(Blockly.KW_SPEED1)
        .setCheck(Number);
    this.setPreviousStatement(true, null);
	this.setInputsInline(true);
    this.setNextStatement(true, null);
  }
};
Blockly.Blocks.kw_stepperspeed2 = {
 init: function() {
	 this.setColour(100);
     this.appendDummyInput("")
   this.appendValueInput("step1", Number)
		.appendField(Blockly.KW_STEP1)
        .setCheck(Number);
    this.setPreviousStatement(true, null);2019/8/30
	this.setInputsInline(true);
    this.setNextStatement(true, null);
  }
};

Blockly.Blocks._4linelcd = {
 init: function() {
	 this.setColour(100);
     this.appendDummyInput("")
	     .appendField(Blockly.KW_4LINELCD)
     this.appendValueInput("RS", Number)
	   .appendField(Blockly.KW_RS)
        .setCheck(Number);
   this.appendValueInput("RW", Number)
		.appendField(Blockly.KW_RW)
        .setCheck(Number);
		   this.appendValueInput("E", Number)
		.appendField(Blockly.KW_E)
        .setCheck(Number);
		   this.appendValueInput("DB4", Number)
		.appendField(Blockly.KW_DB4)
        .setCheck(Number);
		   this.appendValueInput("DB5", Number)
		.appendField(Blockly.KW_DB5)
        .setCheck(Number);
		   this.appendValueInput("DB6", Number)
		.appendField(Blockly.KW_DB6)
        .setCheck(Number);
		   this.appendValueInput("DB7", Number)
		.appendField(Blockly.KW_DB7)
        .setCheck(Number);
    this.setPreviousStatement(true, null);
	this.setInputsInline(true);
    this.setNextStatement(true, null);
  }
};

Blockly.Blocks._8linelcd = {
 init: function() {
	 this.setColour(100);
     this.appendDummyInput("")
	     .appendField(Blockly.KW_8LINELCD)
     this.appendValueInput("_RS", Number)
	   .appendField(Blockly.KW_RS1)
        .setCheck(Number);
   this.appendValueInput("_RW", Number)
		.appendField(Blockly.KW_RW1)
        .setCheck(Number);
		 this.appendValueInput("_E", Number)
		.appendField(Blockly.KW_E1)
        .setCheck(Number);
		   this.appendValueInput("_DB0", Number)
		.appendField(Blockly.KW_DB01)
        .setCheck(Number);
				   this.appendValueInput("_DB1", Number)
		.appendField(Blockly.KW_DB11)
        .setCheck(Number);
				   this.appendValueInput("_DB2", Number)
		.appendField(Blockly.KW_DB21)
        .setCheck(Number);
				   this.appendValueInput("_DB3", Number)
		.appendField(Blockly.KW_DB31)
        .setCheck(Number);
		   this.appendValueInput("_DB4", Number)
		.appendField(Blockly.KW_DB41)
        .setCheck(Number);
		   this.appendValueInput("_DB5", Number)
		.appendField(Blockly.KW_DB51)
        .setCheck(Number);
		   this.appendValueInput("_DB6", Number)
		.appendField(Blockly.KW_DB61)
        .setCheck(Number);
		   this.appendValueInput("_DB7", Number)
		.appendField(Blockly.KW_DB71)
        .setCheck(Number);
    this.setPreviousStatement(true, null);
	this.setInputsInline(true);
    this.setNextStatement(true, null);
  }
};
//rgb超声波模块初始化
Blockly.Blocks.kw_initrgbultrasonic = {
 init: function() {
	 this.setColour(100);
     this.appendDummyInput("")
	     .appendField(Blockly.KW_INITRGBULTRASONIC)
     this.appendValueInput("ultrasonicpin", Number)
	   .appendField(Blockly.KW_ULTRASONICPIN)
        .setCheck(Number);
   this.appendValueInput("rgbpin", Number)
		.appendField(Blockly.KW_RGBPIN)
        .setCheck(Number);
    this.setPreviousStatement(true, null);
	this.setInputsInline(true);
    this.setNextStatement(true, null);
  }
};
/*/设置RGB超声波模块颜色
Blockly.Blocks.kw_setcolor = {
   init: function() {
    this.setColour(100);
    this.appendDummyInput("")
        .appendField(Blockly.KW_SETCOLOR)
		.appendField(new Blockly.FieldDropdown(KW_RGBPOSITION), "rgbposition");
   this.appendDummyInput("")
			.appendField(new Blockly.FieldDropdown(KE_RGBCOLOR), "rgbcolor");
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
	this.setInputsInline(true);
  }
};*/
//设置RGB超声波模块颜色样式
Blockly.Blocks.kw_setcolorandstyle = {
   init: function() {
    this.setColour(100);
    this.appendDummyInput("")
        .appendField(Blockly.KW_SETCOLOR)
		.appendField(new Blockly.FieldDropdown(KW_RGBPOSITION), "rgbposition");
   this.appendDummyInput("")
			.appendField(new Blockly.FieldDropdown(KE_RGBCOLOR), "rgbcolor");
			this.appendDummyInput("")
			.appendField(Blockly.KW_SETSTYLE)
			.appendField(new Blockly.FieldDropdown(KE_RGBSTYLE), "rgbstyle");
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
	this.setInputsInline(true);
  }
};
/*/设置RGB超声波模块呼吸显示
Blockly.Blocks.kw_setrgbbreathe = {
   init: function() {
    this.setColour(100);
    this.appendDummyInput("")
        .appendField(Blockly.KW_SETCOLORS)
		.appendField(new Blockly.FieldDropdown(KW_RGBPOSITION), "rgbposition");
		this.appendDummyInput("")
		.appendField(Blockly.KW_SETRGBBREATHE)
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
	this.setInputsInline(true);
  }
};*/
//RGB超声波模块读取超声波距离
Blockly.Blocks.kw_readultrasonicdistance = {
  init: function() {
    this.setColour(100);
    this.appendDummyInput("")
	    .appendField(Blockly.KW_READULTRASONICDISTANCE)
    this.setOutput(true, Number);
	this.setInputsInline(true);
  }
};
//8x8ledinit 8x8点阵屏初始化
Blockly.Blocks.x8ledinit = {
init:function(){
this.setColour(100);
this.appendDummyInput("")
.appendField(Blockly.KW_8X8LEDINIT)
  .appendField("ROW_0")
  .appendField(new Blockly.FieldDropdown([
    ['0', "0"],
    ['1', "1"],
    ['2', "2"],
    ['3', "3"],
    ['4', "4"],
    ['5', "5"],
    ['6', "6"],
    ['7', "7"],
    ['8', "8"],
    ['9', "9"],
    ['10', "10"],
    ['11', "11"],
    ['12', "12"],
    ['13', "13"],
    ['A0', "A0"],
    ['A1', "A1"],
    ['A2', "A2"],
    ['A3', "A3"],
    ['A4', "A4"],
    ['A5', "A5"],
  ]),"ROW_0s")
  .appendField("ROW_1")
  .appendField(new Blockly.FieldDropdown([
    ['0', "0"],
    ['1', "1"],
    ['2', "2"],
    ['3', "3"],
    ['4', "4"],
    ['5', "5"],
    ['6', "6"],
    ['7', "7"],
    ['8', "8"],
    ['9', "9"],
    ['10', "10"],
    ['11', "11"],
    ['12', "12"],
    ['13', "13"],
    ['A0', "A0"],
    ['A1', "A1"],
    ['A2', "A2"],
    ['A3', "A3"],
    ['A4', "A4"],
    ['A5', "A5"],
  ]),"ROW_1s")
   .appendField("ROW_2")
  .appendField(new Blockly.FieldDropdown([
    ['0', "0"],
    ['1', "1"],
    ['2', "2"],
    ['3', "3"],
    ['4', "4"],
    ['5', "5"],
    ['6', "6"],
    ['7', "7"],
    ['8', "8"],
    ['9', "9"],
    ['10', "10"],
    ['11', "11"],
    ['12', "12"],
    ['13', "13"],
    ['A0', "A0"],
    ['A1', "A1"],
    ['A2', "A2"],
    ['A3', "A3"],
    ['A4', "A4"],
    ['A5', "A5"],
  ]),"ROW_2s")
  .appendField("ROW_3")
  .appendField(new Blockly.FieldDropdown([
    ['0', "0"],
    ['1', "1"],
    ['2', "2"],
    ['3', "3"],
    ['4', "4"],
    ['5', "5"],
    ['6', "6"],
    ['7', "7"],
    ['8', "8"],
    ['9', "9"],
    ['10', "10"],
    ['11', "11"],
    ['12', "12"],
    ['13', "13"],
    ['A0', "A0"],
    ['A1', "A1"],
    ['A2', "A2"],
    ['A3', "A3"],
    ['A4', "A4"],
    ['A5', "A5"],
  ]),"ROW_3s")
   .appendField("ROW_4")
  .appendField(new Blockly.FieldDropdown([
    ['0', "0"],
    ['1', "1"],
    ['2', "2"],
    ['3', "3"],
    ['4', "4"],
    ['5', "5"],
    ['6', "6"],
    ['7', "7"],
    ['8', "8"],
    ['9', "9"],
    ['10', "10"],
    ['11', "11"],
    ['12', "12"],
    ['13', "13"],
    ['A0', "A0"],
    ['A1', "A1"],
    ['A2', "A2"],
    ['A3', "A3"],
    ['A4', "A4"],
    ['A5', "A5"],
  ]),"ROW_4s")
  .appendField("ROW_5")
  .appendField(new Blockly.FieldDropdown([
    ['0', "0"],
    ['1', "1"],
    ['2', "2"],
    ['3', "3"],
    ['4', "4"],
    ['5', "5"],
    ['6', "6"],
    ['7', "7"],
    ['8', "8"],
    ['9', "9"],
    ['10', "10"],
    ['11', "11"],
    ['12', "12"],
    ['13', "13"],
    ['A0', "A0"],
    ['A1', "A1"],
    ['A2', "A2"],
    ['A3', "A3"],
    ['A4', "A4"],
    ['A5', "A5"],
  ]),"ROW_5s")
   .appendField("ROW_6")
  .appendField(new Blockly.FieldDropdown([
    ['0', "0"],
    ['1', "1"],
    ['2', "2"],
    ['3', "3"],
    ['4', "4"],
    ['5', "5"],
    ['6', "6"],
    ['7', "7"],
    ['8', "8"],
    ['9', "9"],
    ['10', "10"],
    ['11', "11"],
    ['12', "12"],
    ['13', "13"],
    ['A0', "A0"],
    ['A1', "A1"],
    ['A2', "A2"],
    ['A3', "A3"],
    ['A4', "A4"],
    ['A5', "A5"],
  ]),"ROW_6s")
  .appendField("ROW_7")
  .appendField(new Blockly.FieldDropdown([
    ['0', "0"],
    ['1', "1"],
    ['2', "2"],
    ['3', "3"],
    ['4', "4"],
    ['5', "5"],
    ['6', "6"],
    ['7', "7"],
    ['8', "8"],
    ['9', "9"],
    ['10', "10"],
    ['11', "11"],
    ['12', "12"],
    ['13', "13"],
    ['A0', "A0"],
    ['A1', "A1"],
    ['A2', "A2"],
    ['A3', "A3"],
    ['A4', "A4"],
    ['A5', "A5"],
  ]),"ROW_7s")
  .appendField("LED_A")
  .appendField(new Blockly.FieldDropdown([
    ['0', "0"],
    ['1', "1"],
    ['2', "2"],
    ['3', "3"],
    ['4', "4"],
    ['5', "5"],
    ['6', "6"],
    ['7', "7"],
    ['8', "8"],
    ['9', "9"],
    ['10', "10"],
    ['11', "11"],
    ['12', "12"],
    ['13', "13"],
    ['A0', "A0"],
    ['A1', "A1"],
    ['A2', "A2"],
    ['A3', "A3"],
    ['A4', "A4"],
    ['A5', "A5"],
  ]),"LED_A1")
  .appendField("LED_B")
  .appendField(new Blockly.FieldDropdown([
    ['0', "0"],
    ['1', "1"],
    ['2', "2"],
    ['3', "3"],
    ['4', "4"],
    ['5', "5"],
    ['6', "6"],
    ['7', "7"],
    ['8', "8"],
    ['9', "9"],
    ['10', "10"],
    ['11', "11"],
    ['12', "12"],
    ['13', "13"],
    ['A0', "A0"],
    ['A1', "A1"],
    ['A2', "A2"],
    ['A3', "A3"],
    ['A4', "A4"],
    ['A5', "A5"],
  ]),"LED_B1")
   .appendField("LED_C")
  .appendField(new Blockly.FieldDropdown([
    ['0', "0"],
    ['1', "1"],
    ['2', "2"],
    ['3', "3"],
    ['4', "4"],
    ['5', "5"],
    ['6', "6"],
    ['7', "7"],
    ['8', "8"],
    ['9', "9"],
    ['10', "10"],
    ['11', "11"],
    ['12', "12"],
    ['13', "13"],
    ['A0', "A0"],
    ['A1', "A1"],
    ['A2', "A2"],
    ['A3', "A3"],
    ['A4', "A4"],
    ['A5', "A5"],
  ]),"LED_C1")
  .appendField("LED_D")
  .appendField(new Blockly.FieldDropdown([
    ['0', "0"],
    ['1', "1"],
    ['2', "2"],
    ['3', "3"],
    ['4', "4"],
    ['5', "5"],
    ['6', "6"],
    ['7', "7"],
    ['8', "8"],
    ['9', "9"],
    ['10', "10"],
    ['11', "11"],
    ['12', "12"],
    ['13', "13"],
    ['A0', "A0"],
    ['A1', "A1"],
    ['A2', "A2"],
    ['A3', "A3"],
    ['A4', "A4"],
    ['A5', "A5"],
  ]),"LED_D1")
   .appendField("LED_E")
  .appendField(new Blockly.FieldDropdown([
    ['0', "0"],
    ['1', "1"],
    ['2', "2"],
    ['3', "3"],
    ['4', "4"],
    ['5', "5"],
    ['6', "6"],
    ['7', "7"],
    ['8', "8"],
    ['9', "9"],
    ['10', "10"],
    ['11', "11"],
    ['12', "12"],
    ['13', "13"],
    ['A0', "A0"],
    ['A1', "A1"],
    ['A2', "A2"],
    ['A3', "A3"],
    ['A4', "A4"],
    ['A5', "A5"],
  ]),"LED_E1")
  .appendField("LED_F")
  .appendField(new Blockly.FieldDropdown([
    ['0', "0"],
    ['1', "1"],
    ['2', "2"],
    ['3', "3"],
    ['4', "4"],
    ['5', "5"],
    ['6', "6"],
    ['7', "7"],
    ['8', "8"],
    ['9', "9"],
    ['10', "10"],
    ['11', "11"],
    ['12', "12"],
    ['13', "13"],
    ['A0', "A0"],
    ['A1', "A1"],
    ['A2', "A2"],
    ['A3', "A3"],
    ['A4', "A4"],
    ['A5', "A5"],
  ]),"LED_F1")
   .appendField("LED_G")
  .appendField(new Blockly.FieldDropdown([
    ['0', "0"],
    ['1', "1"],
    ['2', "2"],
    ['3', "3"],
    ['4', "4"],
    ['5', "5"],
    ['6', "6"],
    ['7', "7"],
    ['8', "8"],
    ['9', "9"],
    ['10', "10"],
    ['11', "11"],
    ['12', "12"],
    ['13', "13"],
    ['A0', "A0"],
    ['A1', "A1"],
    ['A2', "A2"],
    ['A3', "A3"],
    ['A4', "A4"],
    ['A5', "A5"],
  ]),"LED_G1")
  .appendField("LED_H")
  .appendField(new Blockly.FieldDropdown([
    ['0', "0"],
    ['1', "1"],
    ['2', "2"],
    ['3', "3"],
    ['4', "4"],
    ['5', "5"],
    ['6', "6"],
    ['7', "7"],
    ['8', "8"],
    ['9', "9"],
    ['10', "10"],
    ['11', "11"],
    ['12', "12"],
    ['13', "13"],
    ['A0', "A0"],
    ['A1', "A1"],
    ['A2', "A2"],
    ['A3', "A3"],
    ['A4', "A4"],
    ['A5', "A5"],
  ]),"LED_H1")
  this.setPreviousStatement(true,null);
   this.setNextStatement(true,null);
  this.setTooltip('');
  }
  };




  //8x8led点阵屏显示
  Blockly.Blocks.x8leddisplay = {
   init: function() {
    this.setColour(100);
    this.appendDummyInput("")
        .appendField(Blockly.KW_MAXIMAGES)
		.appendField(new Blockly.FieldDropdown(KW_MAXIMAGE), "maximage");
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
	this.setInputsInline(true);
  }

};
//不断扫描显示x8ledloopscan
Blockly.Blocks.x8ledloopscan = {
init:function(){
this.setColour(100);
 this.appendDummyInput("")
   .appendField(Blockly.ARDUINO_X8LEDLOOPSCAN)
this.setPreviousStatement(true,null);
 this.setNextStatement(true,null);
this.setTooltip('');
}
};
//74h初始化 74hinit
Blockly.Blocks._74hinit = {
init:function(){
this.setColour(100);
this.appendDummyInput("")
.appendField(Blockly.ARDUINO__74HINIT)
  .appendField("BIT_CHOICE_1")
  .appendField(new Blockly.FieldDropdown([
    ['0', "0"],
    ['1', "1"],
    ['2', "2"],
    ['3', "3"],
    ['4', "4"],
    ['5', "5"],
    ['6', "6"],
    ['7', "7"],
    ['8', "8"],
    ['9', "9"],
    ['10', "10"],
    ['11', "11"],
    ['12', "12"],
    ['13', "13"],
    ['A0', "A0"],
    ['A1', "A1"],
    ['A2', "A2"],
    ['A3', "A3"],
    ['A4', "A4"],
    ['A5', "A5"],
  ]),"BIT_CHOICE_11")
  .appendField("BIT_CHOICE_2")
  .appendField(new Blockly.FieldDropdown([
    ['0', "0"],
    ['1', "1"],
    ['2', "2"],
    ['3', "3"],
    ['4', "4"],
    ['5', "5"],
    ['6', "6"],
    ['7', "7"],
    ['8', "8"],
    ['9', "9"],
    ['10', "10"],
    ['11', "11"],
    ['12', "12"],
    ['13', "13"],
    ['A0', "A0"],
    ['A1', "A1"],
    ['A2', "A2"],
    ['A3', "A3"],
    ['A4', "A4"],
    ['A5', "A5"],
  ]),"BIT_CHOICE_22")
   .appendField("BIT_CHOICE_3")
  .appendField(new Blockly.FieldDropdown([
    ['0', "0"],
    ['1', "1"],
    ['2', "2"],
    ['3', "3"],
    ['4', "4"],
    ['5', "5"],
    ['6', "6"],
    ['7', "7"],
    ['8', "8"],
    ['9', "9"],
    ['10', "10"],
    ['11', "11"],
    ['12', "12"],
    ['13', "13"],
    ['A0', "A0"],
    ['A1', "A1"],
    ['A2', "A2"],
    ['A3', "A3"],
    ['A4', "A4"],
    ['A5', "A5"],
  ]),"BIT_CHOICE_33")
  .appendField("BIT_CHOICE_4")
  .appendField(new Blockly.FieldDropdown([
    ['0', "0"],
    ['1', "1"],
    ['2', "2"],
    ['3', "3"],
    ['4', "4"],
    ['5', "5"],
    ['6', "6"],
    ['7', "7"],
    ['8', "8"],
    ['9', "9"],
    ['10', "10"],
    ['11', "11"],
    ['12', "12"],
    ['13', "13"],
    ['A0', "A0"],
    ['A1', "A1"],
    ['A2', "A2"],
    ['A3', "A3"],
    ['A4', "A4"],
    ['A5', "A5"],
  ]),"BIT_CHOICE_44")
   .appendField("STCP_PIN")
  .appendField(new Blockly.FieldDropdown([
    ['0', "0"],
    ['1', "1"],
    ['2', "2"],
    ['3', "3"],
    ['4', "4"],
    ['5', "5"],
    ['6', "6"],
    ['7', "7"],
    ['8', "8"],
    ['9', "9"],
    ['10', "10"],
    ['11', "11"],
    ['12', "12"],
    ['13', "13"],
    ['A0', "A0"],
    ['A1', "A1"],
    ['A2', "A2"],
    ['A3', "A3"],
    ['A4', "A4"],
    ['A5', "A5"],
  ]),"STCP_PIN1")
  .appendField("SHCP_PIN")
  .appendField(new Blockly.FieldDropdown([
    ['0', "0"],
    ['1', "1"],
    ['2', "2"],
    ['3', "3"],
    ['4', "4"],
    ['5', "5"],
    ['6', "6"],
    ['7', "7"],
    ['8', "8"],
    ['9', "9"],
    ['10', "10"],
    ['11', "11"],
    ['12', "12"],
    ['13', "13"],
    ['A0', "A0"],
    ['A1', "A1"],
    ['A2', "A2"],
    ['A3', "A3"],
    ['A4', "A4"],
    ['A5', "A5"],
  ]),"SHCP_PIN1")
   .appendField("DATA_PIN")
  .appendField(new Blockly.FieldDropdown([
    ['0', "0"],
    ['1', "1"],
    ['2', "2"],
    ['3', "3"],
    ['4', "4"],
    ['5', "5"],
    ['6', "6"],
    ['7', "7"],
    ['8', "8"],
    ['9', "9"],
    ['10', "10"],
    ['11', "11"],
    ['12', "12"],
    ['13', "13"],
    ['A0', "A0"],
    ['A1', "A1"],
    ['A2', "A2"],
    ['A3', "A3"],
    ['A4', "A4"],
    ['A5', "A5"],
  ]),"DATA_PIN1")
  this.setPreviousStatement(true,null);
   this.setNextStatement(true,null);
  this.setTooltip('');
  }
  };
//74h数码管显示 _74hinitisplay
Blockly.Blocks._74hinitisplay = {
init:function(){
this.setColour(100);
this.appendDummyInput("")
  .appendField(Blockly.ARDUINO_74HDISPLAY)
  this.appendValueInput("_74hinitisplays", Number)
this.setPreviousStatement(true,null);
 this.setNextStatement(true,null);
this.setTooltip('');
}
};
//74h熄灭 _74hoff
Blockly.Blocks._74hoff = {
init:function(){
this.setColour(100);
this.appendDummyInput("")
  .appendField(Blockly.ARDUINO_74HOFF)
this.setPreviousStatement(true,null);
 this.setNextStatement(true,null);
this.setTooltip('');
}
};
