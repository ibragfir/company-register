#ifndef __PROGTEST__
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
#endif /* __PROGTEST__ */

struct Data{
	string uname;
	string uaddr;
	string comp;
	string compaddr;
};
class Node{
public:
	string name;
	string addr;
	Node* next;
};
class CIterator{
  Node* head;
  Node* del_head;
   public:
    bool           AtEnd          ( void ) const{
      if(!head) return true; else return false;
    }
    void           Next           ( void ){
      head=head->next;
    }
    const string & Name           ( void ) const{
      return head->name;
    }
    const string & Address        ( void ) const{
      return head->addr;
    }
    CIterator(Node* h){
      head=h;
      del_head=h;
    }
    CIterator(){
      head=NULL;
      del_head=NULL;
    }
    ~CIterator(void){
     Node* temp;                  //# start at the head.
      while (del_head){       //# traverse entire list.
        temp = del_head;              //# save node pointer.
        del_head = del_head->next;        //# advance to next.
        delete temp;
      }                           //# free the saved one.
      del_head = NULL; 
    }
};
 class CCompanyIndex{
   Data** array;
   Data** array2;
   int flag;
   int MAX;
   int amount;
  public:
   CCompanyIndex ( void ){
      flag  = 0;
      MAX   = 10;
      amount= 0;
      array = NULL;
      array2= NULL;
   }
   ~CCompanyIndex( void ){
      for(int i=0;i<amount;i++){
        delete array[i];
        delete array2[i];
      }
      delete [] array;
      delete [] array2;
   }
  bool delete_first(const string & oName,const string & oAddr,const string& cName,const string& cAddr){
      int low=0;
      int high=amount-1;
      int mid;
      while(low<=high){
        mid=(low+high)/2;
         if(oName==array[mid]->uname){
            if(oAddr==array[mid]->uaddr){
              if(cName==array[mid]->comp){
                if(cAddr==array[mid]->compaddr){
                  delete array[mid];
                  for(int i=mid;i<amount-1;i++)
                    array[i]=array[i+1];
                  array[amount-1]=NULL;
                  return true;
                }
                else if(cAddr>array[mid]->compaddr)
                  low=mid+1;
                else
                  high=mid-1;
              }
              else if(cName>array[mid]->comp)
                low=mid+1;
              else
                high=mid-1;
            }
            else if(oAddr>array[mid]->uaddr)
                low=mid+1;
            else
                high=mid-1;
        }
        else if(oName>array[mid]->uname)
            low=mid+1;
        else
            high=mid-1;
      }
   return false;
  }
  bool delete_second(const string & oName,const string & oAddr,const string& cName,const string& cAddr){
      int low=0;
      int high=amount-1;
      int mid;
      while(low<=high){
        mid=(low+high)/2;
         if(cName==array2[mid]->comp){
            if(cAddr==array2[mid]->compaddr){
              if(oName==array2[mid]->uname){
                if(oAddr==array2[mid]->uaddr){
                  delete array2[mid];
                  for(int i=mid;i<amount-1;i++)
                    array2[i]=array2[i+1];
                    array2[amount-1]=NULL;
                  return true;
                }
                else if(oAddr>array2[mid]->uaddr)
                  low=mid+1;
                else
                  high=mid-1;
              }
              else if(oName>array2[mid]->uname)
                low=mid+1;
              else
                high=mid-1;
            }
            else if(cAddr>array2[mid]->compaddr)
                low=mid+1;
            else
                high=mid-1;
        }
        else if(cName>array2[mid]->comp)
            low=mid+1;
        else
            high=mid-1;
      }
   return false;
  } 
  int whereTo(const string & oName,const string & oAddr,const string& cName,const string& cAddr){
    	if(amount==0)
    		return 0;
    	int low=0;
      int high=amount-1;
      int mid;
      int index;
    	while(low<=high){
    		mid=(low+high)/2;
         if(oName==array[mid]->uname){
            if(oAddr==array[mid]->uaddr){
            	if(cName==array[mid]->comp){
            		if(cAddr==array[mid]->compaddr)
            			return -1;
            		else if(cAddr>array[mid]->compaddr)
            			low=mid+1;
            		else
            			high=mid-1;
            	}
            	else if(cName>array[mid]->comp)
            		low=mid+1;
            	else
            		high=mid-1;
        		}
        		else if(oAddr>array[mid]->uaddr)
               	low=mid+1;
            else
               	high=mid-1;
      	 }
      	 else if(oName>array[mid]->uname)
            low=mid+1;
         else
            high=mid-1;
      }
      index=low;
      for(int i=amount;i>index;i--)
         array[i]=array[i-1];
      //cout<<array[index+1]->uname<<' '<<array[index]->uaddr<<endl;
      return index;
	}
	int whereTo2(const string & oName,const string & oAddr,const string& cName,const string& cAddr){
    if(amount==0)
        return 0;
      int low=0;
      int high=amount-1;
      int mid;
      int index;
      while(low<=high){
        mid=(low+high)/2;
         if(cName==array2[mid]->comp){
            if(cAddr==array2[mid]->compaddr){
              if(oName==array2[mid]->uname){
                if(oAddr==array2[mid]->uaddr)
                  return -1;
                else if(oAddr>array2[mid]->uaddr)
                  low=mid+1;
                else
                  high=mid-1;
              }
              else if(oName>array2[mid]->uname)
                low=mid+1;
              else
                high=mid-1;
            }
            else if(cAddr>array2[mid]->compaddr)
                low=mid+1;
            else
                high=mid-1;
        }
        else if(cName>array2[mid]->comp)
            low=mid+1;
        else
            high=mid-1;
      }
      index=low;
      for(int i=amount;i>index;i--){
         array2[i]=array2[i-1];
      }
      return index;
	}
  bool sort_Owners(const string & oName,const string & oAddr, const string & cName, const string & cAddr){
    	int pos=whereTo(oName,oAddr,cName,cAddr);
      if(pos<0)
        return false;
    	array[pos] = new Data;
      array[pos]->uname=oName;
      array[pos]->uaddr=oAddr;
      array[pos]->comp=cName;
      array[pos]->compaddr=cAddr;
    	return true;
  }
  bool sort_Company(const string & oName,const string & oAddr, const string & cName, const string & cAddr){
    	int pos=whereTo2(oName,oAddr,cName,cAddr);
    	array2[pos] = new Data;
      array2[pos]->uname=oName;
      array2[pos]->uaddr=oAddr;
      array2[pos]->comp =cName;
      array2[pos]->compaddr=cAddr;
            //cout<<"pos= "<<pos<<endl;
    	return true;
  }
  bool Add(const string & oName,const string & oAddr, const string & cName, const string & cAddr){
      if(!flag){
      array =new Data*[MAX];
      array2=new Data*[MAX];
      flag  = 1;
      }
    	if(amount==MAX-1){
      	Data** tmp;
        Data** tmp2;
      	tmp =new Data* [MAX];
        tmp2=new Data* [MAX];
      	for(int i=0;i<amount;i++){
      	  tmp[i] =array[i];
          tmp2[i]=array2[i];
        }
      	delete [] array;
        delete [] array2;
      	MAX*=2;
      	array =new Data* [MAX];
        array2=new Data* [MAX];
      	for(int i=0;i<amount;i++){
      	  array[i] =tmp[i];  
          array2[i]=tmp2[i];
        }
      	delete [] tmp;	
        delete [] tmp2;
    	}
    	if(sort_Owners(oName,oAddr,cName,cAddr) && sort_Company(oName,oAddr,cName,cAddr)){
    		amount++;
    		return true;
    	}
    	else
    		return false;
  }
  bool Del(const string & oName,const string & oAddr, const string & cName, const string & cAddr){
    if(delete_first(oName,oAddr,cName,cAddr) && delete_second(oName,oAddr,cName,cAddr)){
      amount--;
      return true;
    }
    else  return false;
  }
  void print(){
    for(int i=0;i<amount;i++){
      cout<<array[i]->uname<<" "<<array[i]->uaddr<<" "<<array[i]->comp<<" "<<array[i]->compaddr<<endl;
    }
  }
  CIterator* SearchOwner(const string & oName,const string & oAddr)const{
      int low=0;
      int high=amount-1;
      int mid;
      Node *curr,*head;
      head=NULL;
      while(low<=high){
        mid=(low+high)/2;
         if(oName==array[mid]->uname){
            if(oAddr==array[mid]->uaddr){
              int ind=mid;
              while(oName==array[mid]->uname && oAddr==array[mid]->uaddr){
                curr=new Node;
                curr->name=array[mid]->comp;
                curr->addr=array[mid]->compaddr;
                curr->next=head;
                head=curr;
                if(mid>=amount-1)
                  break;
                mid++;
              }
              //cout<<"ind= "<<ind<<endl;
              if(ind!=0){
                ind--;
              while(oName==array[ind]->uname && oAddr==array[ind]->uaddr){
                curr=new Node;
                curr->name=array[ind]->comp;
                curr->addr=array[ind]->compaddr;
                curr->next=head;
                head=curr;
                if(ind==0)
                  break;
                ind--;
              }
              }
              CIterator* x=new CIterator(head);
              return x;
            }
            else if(oAddr>array[mid]->uaddr)
                low=mid+1;
            else
                high=mid-1;
        }
        else if(oName>array[mid]->uname)
            low=mid+1;
        else
            high=mid-1;
      }
    return NULL;
  }
  CIterator* SearchCompany(const string & cName,const string & cAddr ) const{
      int low=0;
      int high=amount-1;
      int mid;
      Node *curr,*head;
      head=NULL;
      while(low<=high){
        mid=(low+high)/2;
         if(cName==array2[mid]->comp){
            if(cAddr==array2[mid]->compaddr){
              int ind=mid;
              if(mid!=amount-1){
                 mid++;
                while(cName==array2[mid]->comp && cAddr==array2[mid]->compaddr){
                  curr=new Node;
                  curr->name=array2[mid]->uname;
                  curr->addr=array2[mid]->uaddr;
                  curr->next=head;
                  head=curr;
                  if(mid>=amount-1)
                    break;
                  mid++;
                }
              }
              //cout<<"ind= "<<ind<<endl;

              while(cName==array2[ind]->comp && cAddr==array2[ind]->compaddr){
                curr=new Node;
                curr->name=array2[ind]->uname;
                curr->addr=array2[ind]->uaddr;
                curr->next=head;
                head=curr;
                if(ind==0)
                  break;
                ind--;
              }
              CIterator* x=new CIterator(head);
              return x;
            }
            else if(cAddr>array2[mid]->compaddr)
                low=mid+1;
            else
                high=mid-1;
        }
        else if(cName>array2[mid]->comp)
            low=mid+1;
        else
            high=mid-1;
      }
    return NULL;
  }
  void print_amount(){
    cout<<"amount= "<<amount<<endl; 
  }
};
#ifndef __PROGTEST__

void  showResults ( CIterator * it )
 {
   while ( ! it -> AtEnd () )
    {
      cout << it -> Name () << ",  " << it -> Address () << endl;
      it -> Next ();
    }
 }

int main(){
  CIterator * it;
bool        status;
CCompanyIndex  b1;
status = b1 . Add ( "Smith", "Oak road", "ACME, Ltd.", "One ACME road" );
// status = true
status = b1 . Add ( "Brown", "Second street", "ACME, Ltd.", "Mountain road" );
// status = true
status = b1 . Add ( "Hacker", "5-th avenue", "Forks and Knives, Ltd.", "Cutlery avenue" );
// status = true
status = b1 . Add ( "Hacker", "7-th avenue", "Child toys, Inc.", "Red light district" );
// status = true
status = b1 . Add ( "Smith", "Oak road", "ACME, Ltd.", "Mountain road" );
// status = true
status = b1 . Add ( "Hacker", "5-th avenue", "ACME, Ltd.", "One ACME road" );
// status = true
status = b1 . Add ( "Hacker", "7-th avenue", "ACME, Ltd.", "Mountain road" );
// status = true
status = b1 . Add ("Hacker","7-th avenue", "ACME, Ltd.", "");
// cout<<"status= "<<status<<endl;
status = b1 . Del ("Hacker", "7-th avenue", "ACME, Ltd.", "Mountain road" );
//cout<<"status= "<<status<<endl;
status = b1 . Del ("Hacker", "7-th avenue", "ACME, Ltd.", "Mountain road" );
cout<<"status= "<<status<<endl;
it = b1 . SearchOwner ( "Brown", "Second street" );
showResults ( it );
/*
----8<----8<----8<----8<----
ACME, Ltd., Mountain road
----8<----8<----8<----8<----
*/
delete it;
it = b1 . SearchOwner ( "Hacker", "Oak road" );
// it = NULL
it = b1 . SearchOwner ( "Hacker", "7-th avenue" );
showResults ( it );
/*
----8<----8<----8<----8<----
Child toys, Inc., Red light district
ACME, Ltd., Mountain road
----8<----8<----8<----8<----
*/
delete it;
cout<<"success first part\n\n";
it = b1 . SearchCompany ( "ACME, Ltd.", "Mountain road" );
showResults ( it );
/*
----8<----8<----8<----8<----
Hacker, 7-th avenue
Brown, Second street
Smith, Oak road
----8<----8<----8<----8<----
*/
delete it;
cout<<"success second part\n\n";
//b1.print();
it = b1 . SearchCompany ( "Child toys, Inc.", "Mountain road" );
// it = NULL
status = b1 . Del ( "Smith", "Oak road", "Child toys, Inc.", "Red light district" );
// status = false
status = b1 . Del ( "Smith", "Oak road", "ACME, Ltd.", "Mountain road" );
// status = true
//cout<<"FUCK\n";
//b1.print();

it = b1 . SearchOwner ( "Smith", "Oak road" );
showResults ( it );
/*
----8<----8<----8<----8<----
ACME, Ltd., One ACME road
----8<----8<----8<----8<----
*/
delete it;
//status = b1 . Add ( "Smith", "Oak road", "ACME, Ltd.", "One ACME road" );
// status = false
//cout<<status<<endl;


return 0;
}
#endif /* __PROGTEST__ */
