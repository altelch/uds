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
  uint8_t ds[]={0x81};
  struct Session_t diag;

  Serial.println(F("Diag Session"));
  diag.tx_id=0x712;
  diag.rx_id=0x732;
  diag.Data=ds;
  diag.len=1;
  if(uds.Diagnostic_Session_Control(&diag))
    Serial.println(F("UDS Session Error!"));
  else
    uds.print_buffer(diag.Data,diag.len);
  delay(1000);
}
