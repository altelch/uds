#include <mcp_can.h>
#include <mcp_can_dfs.h>
#include <SPI.h>
#include <iso-tp.h>
#include <uds.h>

#define MCP_INT 2

MCP_CAN CAN0(10);
IsoTp isotp(&CAN0, MCP_INT);
UDS uds(&isotp);

struct Session_t session;

void setup()
{
  Serial.begin(1000000);
  pinMode(MCP_INT, INPUT);
  CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ);
  CAN0.setMode(MCP_NORMAL);
  delay(5000);
}

void loop()
{
  uint8_t ds[]={0x00};
  struct Session_t diag;
  uint16_t retval=0;

  Serial.println(F("Diag Session"));
  diag.tx_id=0x7E0;
  diag.rx_id=0x7E8;
  diag.sid=UDS_SID_DIAGNOSTIC_CONTROL;
  diag.Data=ds;
  diag.len=1;
  if(retval=uds.Session(&diag))
  {
    Serial.print(F("UDS Session Error "));
    Serial.print(retval); Serial.print(F(" NRC "));
    Serial.println(retval,HEX);
  }
  else
  {
    Serial.println(F("Established with "));
    uds.print_buffer(diag.Data,diag.len);
  }
  delay(1000);
}
