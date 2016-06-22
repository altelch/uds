#include <mcp_can.h>
#include <mcp_can_dfs.h>
#include <SPI.h>
#include <uds.h>

MCP_CAN CAN0(10);
UDS uds(&CAN0);

struct Session_t session;

void setup()
{
  Serial.begin(1000000);
  pinMode(2, INPUT);
  CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ);
  CAN0.setMode(MCP_NORMAL);
}

void loop()
{ 
}
