
#ifndef MEMBER_H
#define MEMBER_H


#include <iostream>
#include <map>

using namespace std;

class Member {
    public:
            
        static int count();
        
        static int countID;
        
        static int size;
        
        int id;
        
        Member();
        
        ~Member();

        int numFollowers() ;
        
        int numFollowing() ;
        
        void follow(Member &member);
        
        void unfollow(Member &member);
        
    private:
        map<int, Member*> followers;
        map<int, Member*> following;
};


#endif
