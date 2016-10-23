#ifndef IPAddress_h
#define IPAddress_h
#include <stdint.h>
#include "Printable.h"

class IPAddress : public Printable {
private:
    uint32_t _address;  // IPv4 address
    // Access the raw byte array containing the address.  Because this returns a pointer
    // to the internal structure rather than a copy of the address this function should only
    // be used when you know that the usage of the returned uint8_t* will be transient and not
    // stored.
    uint8_t* raw_address() { return (uint8_t*)&_address; };

public:
    // Constructors
    IPAddress();
    IPAddress(uint8_t first_octet, uint8_t second_octet, uint8_t third_octet, uint8_t fourth_octet);
    IPAddress(uint32_t address);
    IPAddress(const uint8_t *address);

    // Overloaded cast operator to allow IPAddress objects to be used where a pointer
    // to a four-byte uint8_t array is expected
    operator uint32_t() { return _address; };
    bool operator==(const IPAddress& addr) { return _address == addr._address; };
    bool operator==(const uint8_t* addr);

    // Overloaded index operator to allow getting and setting individual octets of the address
    uint8_t operator[](int index) const { return ((uint8_t*)&_address)[index]; };
    uint8_t& operator[](int index) { return ((uint8_t*)&_address)[index]; };

    // Overloaded copy operators to allow initialisation of IPAddress objects from other types
    IPAddress& operator=(const uint8_t *address);
    IPAddress& operator=(uint32_t address);

    virtual size_t printTo(Printx& p) const;

    friend class EthernetClass;
    friend class UDP;
    friend class Client;
    friend class Server;
    friend class DhcpClass;
    friend class DNSClient;
};

const IPAddress INADDR_NONE(0,0,0,0);

#endif
