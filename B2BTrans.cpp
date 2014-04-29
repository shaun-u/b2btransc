#include "B2BTrans.h"
#include "log.h"

#include <sstream>
#include <string>

#define MOD_NAME "b2btrans"

EXPORT_SESSION_FACTORY(B2BTransFactory,MOD_NAME);

B2BTransFactory::B2BTransFactory(const string& _app_name)
  : AmSessionFactory(_app_name)
{
}

int B2BTransFactory::onLoad()
{
  DBG("B2BTransFactory loading");
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
  DBG("B2BTransDialog connecting callee\n");

  std::ostringstream os;
  os << "r_uri=" << req.r_uri << "; ";
  os << "to=" << req.to << "; ";
  os << "from_uri=" << req.from_uri << "; ";
  os << "from=" << req.from;
  DBG(os.str().c_str());
  
  connectCallee("<sip:11@192.168.1.111>","sip:11@192.168.1.111",req.from_uri,req.from);
}

void B2BTransDialog::onBye(const AmSipRequest& req)
{
  DBG("onBye: stopSession\n");
  setStopped();
}

