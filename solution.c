#ifndef __PROGTEST__
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
#endif /* __PROGTEST__ */

struct Data
{
  string uname;
  string uaddr;
  string comp;
  string compAddr;
};

class CCompanyIndex{
	Data* array;
   int flag;
   int MAX;
   int amount;

public:
  	CCompanyIndex(){
      flag  = 0;
      MAX   = 1000;
      amount= 0;
      array = NULL;
  	}
   ~CCompanyIndex(){
   	delete [] array;
   }
   int whereTo(const string & oName,const string & oAddr){
      if(amount==0)
         return 0;
      int low=0;
      int high=amount-1;
      int mid;
      int index;
      while(low<=high)
      {
         mid=(low+high)/2;
         if(oName==array[mid].uname){
            if(oAddr==array[mid].uaddr)
               return -1;
            if(oAddr>array[mid].uaddr)
               low=mid+1;
            else
               high=mid-1;
         }
         else if(oName>array[mid].uname)
            low=mid+1;
         else
            high=mid-1;
      }
      index=low;
      for(int i=amount;i>index;i--)
         array[i]=array[i-1];
      return index;

   }
   bool	Add(const string & oName,const string & oAddr,const string & cName,const string & cAddr){
   	if(!flag){
   		array=new Data[MAX];
   	   flag = 1;
      }
   	if(amount==MAX-1){
   		Data* tmp;
   		tmp= new Data [MAX];
   		for(int i=0;i<amount;i++)
   			tmp[i]=array[i];
   		delete [] array;
   		array=NULL;
         MAX*=4;
   		array=new Data [MAX];
   		for(int i=0;i<amount;i++)
   			array[i]=tmp[i];	
   		delete [] tmp;
   	}
   	int pos=whereTo(oName,oAddr);
      if(pos<0)
         return false;
      array[pos].uname=oName;
      array[pos].uaddr=oAddr;
      array[pos].comp=cName;
      array[pos].compAddr=cAddr;
   	amount++;
   	return true;
   }
   
   bool  Del(const string & oName,const string & oAddr){
   	int low=0;
      int mid;
      int high=amount-1;
   		while(low<=high)
         {
            mid=(low+high)/2;
            if(oName==array[mid].uname){
               if(oAddr==array[mid].uaddr){
                  for(int i=mid;i<amount-1;i++)
                     array[i]=array[i+1];
                  amount--;
                  return true;
               }
               if(oAddr>array[mid].uaddr)
                  low=mid+1;
               else
                  high=mid-1;
            }
            else if (oName>array[mid].uname)
               low=mid+1;
            else
               high=mid-1;
   		}
   	return false;
   }
   bool  Search(const string & oName,const string & oAddr,string & cName,string & cAddr)const{
      int low=0;
      int high=amount-1;
      int mid;
      while(low<=high){
         mid=(low+high)/2;
         if(oName==array[mid].uname){
            if(oAddr==array[mid].uaddr){
               cName=array[mid].comp;
               cAddr=array[mid].compAddr;
               return true;
            }
            if(oAddr>array[mid].uaddr)
               low=mid+1;
            else
               high=mid-1;
         }
         else if(oName>array[mid].uname)
            low=mid+1;
         else
            high=mid-1;
      }
      return false;
   }
 };
