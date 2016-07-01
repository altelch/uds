#include <mcp_can.h>
#include <mcp_can_dfs.h>
#include <SPI.h>
#include <iso-tp.h>
#include <uds.h>

MCP_CAN CAN0(10);
IsoTp isotp(&CAN0);
UDS uds(&isotp);

struct Session_t session;

void setup()
{
  Serial.begin(1000000);
  pinMode(2, INPUT);
  CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ);
  CAN0.setMode(MCP_NORMAL);
  delay(5000);
}

void loop()
{
  uint8_t pid=0x00;
  struct Session_t diag;
  uint8_t retval=0;

  Serial.println(F("OBD2 request PIDs: "));
  diag.tx_id=0x7E0;
  diag.rx_id=0x7E8;
  diag.sid=OBD_MODE_SHOW_CURRENT_DATA;
  diag.Data=&pid;
  diag.len=1;
  if(retval=uds.Session(&diag))
  {
    Serial.print(F("OBD2 Error "));
    Serial.print(retval); Serial.print(F(" NRC "));
    Serial.println(diag.nrc);
  }
  else
  {
    uint32_t pids=(uint32_t)diag.Data[0]<<24 | (uint32_t)diag.Data[1]<<16 | (uint32_t)diag.Data[2]<<8 | (uint32_t)diag.Data[3];

    for(uint8_t i=0; i<32;i++) //4 Bytes PIDs as bitfield
    { 
      Serial.print(F("PID ")); Serial.print(32-i);
      if(pids & ((uint32_t)1<<i)) Serial.println(F(" yes")); else Serial.println(F(" no"));
    }
  }
  delay(1000);
}
