#include "Member.h"

int Member::countID = 0;
int Member::size = 0;

Member::Member() {
    
    id = ++countID;
    size++;
}

Member::~Member(){
    size--;
	map <int, Member*> :: iterator i;
	for(i=following.begin(); i!=following.end();i++)
	{
		i->second->followers.erase(this->id);
	}
	
	for(i=followers.begin();i!=followers.end();i++)
	{
		i->second->following.erase(this->id);
	}
}

int Member::count(){
    //return the count of members  
    return Member::size;
}

int Member::numFollowers() {
    //return the number of followers a member has
    return followers.size();
}

int Member::numFollowing() {
    //return the number of following a member is following
    return following.size();
}

void Member::follow(Member &member){
    //follow another member
    //add the member to the vector
    if(&member!=this){
        following[member.id] = &member;
        member.followers[id] = this;
    }
}

void Member::unfollow(Member &member){
    //unfollow another member
    //remove the member from the vector
    if(&member!=this){
        following.erase(member.id);
        member.followers.erase(id);
    }
}