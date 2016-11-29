#ifndef _DINNER_PARTY_H_
#define _DINNER_PARTY_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Party.h"
#include "DinnerPartyTicket.h"

/**
 * DinnerParty is derived from Party
 */
class DinnerParty : public Party
{
 private:
  std::list<std::string> room; // Data structure for containing the party goers in this dinner party
  
  /**
   * Constructor for creating a DinnerParty
   */
  DinnerParty() {}

  friend class PartyFactory;

 public:

  /**
   * Add a person to the party
   * @param name the name of the party goer
   */
  PartyTicket * add(std::string name) {
    /**
     * FIXME 1a:
     *   Pseudo-code
     *    1. add name to the front of room
     *    2. get iterator to the front of the room (this points to the recently added party goer)
     *    3. create a new dinner party ticket (DinnerPartyTicket) with its constructor
     *            Pass to the constructor "this" party, and the iterator from step 2
     *    4. return this new party ticket 
     */
    
    room.push_back(name);
    
    std::list<std::string>::iterator it = room.begin();
    
    DinnerPartyTicket din(this, it);
    
    return &din;
  }

  /**
   * List all the persons currently in the party
   */
  void list() {
    // FIXME 1b: iterate through all the persons here.
    
    std::list<std::string>::iterator it;
    
    std::cout<<"Iterating..."<<std::endl;

    for( it = room.begin(); it != room.end(); ++it)
      std::cout<<"People at the dinner party: "<<*it<<std::endl;
    
  }

  /**
   * Remove the person identified by the iterator from the party
   */
  void remove(std::list<std::string>::iterator it) {
    //FIXME 1c: someone's getting out of hand. Let's ask them to leave.
    
    for(it = room.begin(); it != room.end(); ++it)
      {
	if( *it == "Jane" )
	  {
	    std::cout<<"Party goer: "<<*it<<" is leaving now."<<std::endl;
	    room.remove(*it);
	  }
      }

  }
};
#endif
