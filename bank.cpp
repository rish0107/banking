    /*       TUTORIAL-1
          NAME:RISHABH JAIN
          SEC:C
          ROLL NO:39    */

    #include<iostream>
    #include<string.h>
    using namespace std;

    class seccbank                                  //CLASS TO DECLARE DATA MEMBERS AND METHODS
    {
        private:
            string cname,cadd,cemail;
            long long int cacc,cmob,cbal;
        public:
            void openacc(int);
            void showaccinfo();
            int showparinfo(int);
            int withdraw(int);
            int deposit(int);
            int balinfo(int);
    };

    int acc[10];

    void seccbank::openacc(int c)                   //METHOD TO OPEN AN ACCOUNT
    {
        int flag=0;
        int i=0,j=-1;
        cout<<"\n\tenter account number:\t";
        cin>>cacc;
        acc[c]=cacc;
        flag=0;
        for(i=0;i<c;i++)                    //TO CHECK WHEATHER THE ACCOUNT EXHIST OR NOT
        {
            if(cacc==acc[i])
                {
                    flag++;
                }
        }
        if(flag==0)
        {
            cin.ignore();
            cout<<"\tenter customer name:\t";
            getline(cin,cname);
           // cin.ignore();
            cout<<"\tenter customer address:\t";
            getline(cin,cadd);
            cout<<"\tenter customer mobile number:\t";
            cin>>cmob;
            cin.ignore();
            cout<<"\tenter customer email id:\t";
            getline(cin,cemail);
            cbal=0;
        }
        else
        {
            cout<<"\tsame account number "<<endl;
        }
    }

    void seccbank::showaccinfo()                    //METHOD TO SHOW THE INFORMATION OF ALL THE ACCOUNT
    {
        cout<<"\taccount no.\t"<<cacc<<endl;
        cout<<"\tcustomer name\t"<<cname<<endl;
        cout<<"\tcustomer address\t"<<cadd<<endl;
        cout<<"\tcustomer mobile no.\t"<<cmob<<endl;
        cout<<"\tcustomer email id\t"<<cemail<<endl;
        cout<<"\tcurrent balance\t"<<cbal<<endl;
    }

    int seccbank::showparinfo(int acc)              //METHOD TO INFORMATION OF A PARTICULAR ACCOUNT
    {
            if(acc==cacc)
            {
                cout<<"\taccount no.\t"<<cacc<<endl;
                cout<<"\tcustomer name\t"<<cname<<endl;
                cout<<"\tcustomer address\t"<<cadd<<endl;
                cout<<"\tcustomer mobile no.\t"<<cmob<<endl;
                cout<<"\tcustomer email id\t"<<cemail<<endl;
                cout<<"\tcurrent balance\t"<<cbal<<endl;
                return (1);
            }
    }

    int seccbank::withdraw(int acc)                 //METHOD TO WITHDRAW MONEY FROM THE ACCOUNT
    {
        int amount;
        if(acc==cacc)
        {
            cout<<"\tenter amount to be withdraw\t";
            cin>>amount;
            if(amount>cbal){
                cout<<"\tamount to be withdraw is more than your balance"<<endl;
                return(cacc);}
            else
            {
                cbal=cbal-amount;
                cout<<"\tamount is withdrawl successfully"<<endl;
                return(cacc);
            }
        }
    }

    int seccbank::deposit(int acc)                  //METHOD TO DEPOSIT THE MONEY IN THE ACCOUNT
    {
        int amount;
        if(acc==cacc)
        {
            cout<<"\tenter amount to be deposited\t";
            cin>>amount;
            cbal=cbal+amount;
            cout<<"\taccount is credited in your account"<<endl;
            return (cacc);
        }
    }

    int seccbank::balinfo(int acc)                 //METHOD TO BALANCE INFORMATION OF PARTICULAR ACCOUNT
    {
        if(acc==cacc)
        {
            cout<<"\tyour current balance is\t"<<cbal;
            return (1);
        }
    }

    int main()
    {
        int ch,i=0,acc,flag=1,c=-1;
        seccbank bk[10];
        do
        {
            cout<<"\n\tWELCOME TO SEC C BANK\n"<<endl;      //MENU OF THE PROGRAM
            cout<<"\tOPTIONS ARE"<<endl;
            cout<<"\t1-open an account"<<endl;
            cout<<"\t2-deposit money"<<endl;
            cout<<"\t3-withdraw money"<<endl;
            cout<<"\t4-show balance info"<<endl;
            cout<<"\t5-show particular account info"<<endl;
            cout<<"\t6-show account info"<<endl;
            cout<<"\t7-exit"<<endl;
            cout<<"\tplease enter the suitable option\t";
            cin>>ch;
            switch(ch)
            {
                case 1:
                            c++;
                            bk[i].openacc(c);
                            i++;
                            break;
                case 2:
                        int ft;
                        flag=0;
                        cout<<"\tenter account no in which money is to deposit\t";
                        cin>>acc;
                        for(i=0;i<=c;i++)
                        {
                            ft=bk[i].deposit(acc);
                            flag++;
                            if(ft==acc)
                                break;
                        }
                          if(flag==0)
                            cout<<"\taccount not found"<<endl;
                        break;
                case 3:
                        cout<<"\tenter account no from which money is to be withdraw\t";
                        cin>>acc;
                        flag=0;
                        for(i=0;i<=c;i++)
                        {
                            ft=bk[i].withdraw(acc);
                            if(ft==acc)
                            {
                                flag++;
                                break;
                            }
                        }
                        if(flag==0)
                            cout<<"\taccount not found"<<endl;
                        break;
                case 4:
                        cout<<"\tenter account no for which balance is to be seen\t";
                        cin>>acc;
                        flag=0;
                        for(i=0;i<=c;i++)
                        {
                            if(bk[i].balinfo(acc)==1);
                                flag++;
                        }
                        if(flag==0)
                            cout<<"\taccount not found"<<endl;
                        break;
                case 5:
                        flag=0;
                        cout<<"\tenter account no.\t";
                        cin>>acc;
                        for(i=0;i<=c;i++)
                        {
                            if(bk[i].showparinfo(acc)==1)
                                flag++;
                        }
                          if(flag==0)
                            cout<<"\taccount not found"<<endl;
                        break;
                case 6:
                        if(c>=0)
                        {
                            for(i=0;i<=c;i++)
                            {
                                bk[i].showaccinfo();
                            }
                        }
                        else
                            cout<<"\tno account opened"<<endl;
                        break;
                case 7:
                         break;
                default:
                        cout<<"\twrong choice"<<endl;
            }
        }while(ch<7);
        return 0;
    }
