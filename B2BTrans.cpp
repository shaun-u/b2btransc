#include "B2BTrans.h"
#include "log.h"

#define MOD_NAME "b2btrans"

EXPORT_SESSION_FACTORY(B2BTransFactory,MOD_NAME);

B2BTransFactory::B2BTransFactory(const string& _app_name)
  : AmSessionFactory(_app_name)
{
}

int B2BTransFactory::onLoad()
{
  DBG("B2BTransFactory::onLoad()");
  return 0;
}

AmSession* B2BTransFactory::onInvite(const AmSipRequest& req)
{
  return new B2BTransDialog();
}

B2BTransDialog::B2BTransDialog()
{
}

B2BTransDialog::~B2BTransDialog()
{
}

void B2BTransDialog::onSessionStart(const AmSipRequest& req)
{
  DBG("B2BTransDialog::onSessionStart: Hello World!\n");
}

void B2BTransDialog::onBye(const AmSipRequest& req)
{
  DBG("onBye: stopSession\n");
  setStopped();
}

