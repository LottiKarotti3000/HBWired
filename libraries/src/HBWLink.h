/*
** HBWLink
**
** Combined base class for link implementations that can both send and
** receive events. Pass the same HBWLink instance as both the sender and
** receiver arguments to HBWDevice when both capabilities are needed.
*/

#ifndef HBWLink_h
#define HBWLink_h

#include "HBWired.h"

class HBWLink : public HBWLinkSender, public HBWLinkReceiver {
  public:
    virtual ~HBWLink() {}
};

#endif /* HBWLink_h */
