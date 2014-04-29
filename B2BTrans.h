#ifndef _B2BTRANS_H_
#define _B2BTRANS_H_

#include "AmB2ABSession.h"

class B2BTransFactory: public AmSessionFactory
{
public:
  B2BTransFactory(const string& _app_name);

  int onLoad();
  AmSession* onInvite(const AmSipRequest& req);
};

class B2BTransDialog : public AmB2ABCallerSession
{
    
public:
  B2BTransDialog();
  virtual ~B2BTransDialog();

  void onSessionStart(const AmSipRequest& req);
  void onBye(const AmSipRequest& req);
};

#endif

