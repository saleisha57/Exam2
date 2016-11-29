#ifndef _BIRTHDAY_PARTY_H_
#define _BIRTHDAY_PARTY_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Party.h"
#include "BirthdayPartyTicket.h"

// FIXME 2: Create BirthdayParty and BirthdayPartyTicket to host birthday parties!
// FIXME 3: Update PartyFactory::factory() to allow it to be the ONLY method for creating a BirthdayParty
/**
* BirthdayParty is derived from Party
*/
class BirthdayParty : public Party
{
  private:
  std::list<std::string> party; 

  BirthdayParty() {}

  friend class PartyFactory;

 public:

  PartyTicket * add(std::string name) 
  {
    party.push_back(name);
    
    std::list<std::string>::iterator it = party.begin();
    
    BirthdayPartyTicket birth(this, it);
    
    return &birth;
  }


  void list()
  {
    std::list<std::string>::iterator it;
    
    std::cout<<"Iterating..."<<std::endl;
    
    for( it = party.begin(); it != party.end(); ++it)
      std::cout<<"People at the birthday party: "<<*it<<std::endl;
    
  }
  
  void remove(std::list<std::string>::iterator it) 
  {
    for(it = party.begin(); it != party.end(); ++it)
      {
	if( *it == "Jane" )
	  {
	    std::cout<<"Party goer: "<<*it<<" is leaving now."<<std::endl;
	    party.remove(*it);
	  }
      }

  }

};

#endif
