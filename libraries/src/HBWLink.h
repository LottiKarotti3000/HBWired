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

  protected:
    // Calculate the EEPROM address of a field in a link entry.
    uint16_t linkFieldAddress(uint16_t eepromStart, uint8_t entrySize,
                              uint8_t entryIndex, uint8_t fieldOffset) const {
      return eepromStart + entrySize * entryIndex + fieldOffset;
    }

    // Read a typed field from a link entry. The optional length and byte order
    // arguments preserve HBWDevice::readEEPROM's existing behavior.
    template<typename T>
    void readLinkField(HBWDevice* device, T* value, uint16_t eepromStart,
                       uint8_t entrySize, uint8_t entryIndex,
                       uint8_t fieldOffset, uint16_t length = sizeof(T),
                       boolean lowByteFirst = false) const {
      device->readEEPROM(value,
                         linkFieldAddress(eepromStart, entrySize, entryIndex, fieldOffset),
                         length, lowByteFirst);
    }
};

#endif /* HBWLink_h */
