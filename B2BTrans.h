#ifndef _B2BTRANS_H_
#define _B2BTRANS_H_

#include "AmSession.h"

class B2BTransFactory: public AmSessionFactory
{
public:
  B2BTransFactory(const string& _app_name);

  int onLoad();
  AmSession* onInvite(const AmSipRequest& req);
};

class B2BTransDialog : public AmSession
{
    
public:
  B2BTransDialog();
  virtual ~B2BTransDialog();

  void onSessionStart(const AmSipRequest& req);
  void onBye(const AmSipRequest& req);
};

#endif

