#include<iostream>
#include<conio.h>
#include<fstream>
#include<ctime>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class BankAccount
{
	private:
		int acn;
		char name[30];
		float balance;
		char type;
		int pass;
	public:
		void getData()
		{
			int r,n,j=0;
			PASS:
			cout<<"\nENTER 6 DIGIT PASSWORD : ";
			cin>>pass;
			n=pass;
			while(n!=0)
			{
				r=n%10;
				j++;
				n=n/10;
			}
			if(j!=6)
			{
				cout<<"\n\aPLEASE ENTER VALID PASSWORD..! \n";
				j=0;
				goto PASS;
			}
			fflush(stdin);
			cout<<"\nENTER THE NAME : \n";
			cin.getline(name,30);
			cout<<"\nENTER THE OPENING BALANCE:  ";
			cin>>balance;
			UP:
			cout<<"\nENTER THE ACCOUNT TYPE(S/C) ";
			cin>>type;
			if(!(type=='C' || type=='c' || type=='S' || type=='s'))
			goto UP;
			cout<<"\nACCOUNT CREATED SUCCESSFULLY..!";
		}
		float deposit()
		{
			double amt;
			cout<<"\nENTER THE AMOUNT TO DEPOSIT : ";
			cin>>amt;
				if(amt<=100000)
				{
					balance+=amt;
					cout<<"\n"<<amt<<" AMOUNT DEPOSITED ";
				}
				else
				{
					cout<<"\n\nSORRY, UNPERMITTED CREDIT *_* ";
					return 0;
				}
				return amt;
		}
		float withdraw()
		{
			double amt;
			cout<<"\nENTER THE AMOUNT TO WITHDRAW :";
			cin>>amt;
			if(amt<=balance)
			{
				if(type =='S'|| type=='s')
				{
					if(amt<=50000)
						goto CANGO;
					else
						cout<<"\n\nSORRY, UNPERMITTED DEBIT *_*";
						return 0;
				}
				else
				{
					if(amt<=100000)
					{
						CANGO:
						balance-=amt;
						cout<<"\n"<<amt<<" AMOUNT WITHDRWAN SUCCESSFULLY ";
					}
					else
					{
						cout<<"\n\nSORRY, UNPERMITTED DEBIT *_*";
						return 0;
					}
				}
			}
			else
			{
				cout<<"\nINSUFFICIENT FUND ";
				return 0;
			}
			return amt;
		}
		void display()
		{
			cout<<"\nACCOUNT NUMBER    :   "<<acn;
			cout<<"\nNAME OF CUSTOMER  :   "<<name;
			cout<<"\nCURRENT BALANCE   :   "<<balance<<" Rs. ";
			cout<<"\nACCOUNT TYPE  	  :   ";
			if(type=='C' || type=='c')
			cout<<"CHECKING ACCOUNT";
			else if(type=='S'|| type=='s')
			cout<<"SAVING ACCOUNT ";
		}
		void changepass()
		{
			int npass,cpass,j=0,r,n;
			AGN:
			cout<<"\nENTER THE NEW PASSWORD ";
			cin>>npass;
			n=npass;
			while(n!=0)
			{
				r=n%10;
				j++;
				n=n/10;
			}
			if(j!=6)
			{
				cout<<"\n\aPLEASE ENTER VALID PASSWORD..! \n";
				j=0;
				goto AGN;
			}
			else
			{
				cout<<"\nCONFIRM THE PASSWORD ";
				cin>>cpass;
				if(cpass==npass)
				{
					pass=npass;
					cout<<"\nPASSWORD UPDATED SUCCESSFULLY.!";
				}
				else
				{
					cout<<"\nPASSWORD DON'T MATCH :( ";
				}
			}
		}
		int getAcn()
		{
			return acn;
		}
		void setAcn( int n)
		{
			acn=n;
		}
		void setBal(float b)
		{
			balance=b;
		}
		int getPass()
		{
			return pass;
		}
		float getBalance()
		{
			return balance;
		}
		char getType()
		{
			return type;
		}
		void putName()
		{
			cout<<name;
		}
};
int main()
{
	time_t now=time(0);
	tm *d=localtime(& now);
	BankAccount e;
	ofstream fout,ffout;
	ifstream fin;
	double s;
	int choice,tempac,pass,i=0,k=0,ano;
	char x;
	do
	{
		system("cls");
		cout<<"\n!*!*! GOVERNMENT POLYTECHNIQUE BANK !*!*! \n";
		cout<<"\n1}.OPEN EXISTING ACCOUNT.\n\n2}.CREATE ACCOUNT.\n\n3}.DELETE ACCOUNT.\n\n4}.ADMINSTRATOR LOG IN\n\n5}.QUIT";
		cout<<"\n\nSELECT : ";
		cin>>choice;
		switch(choice)
		{
		case 1:
		{
			system("cls");
			cout<<"\nENTER THE ACCOUNT NUMBER : ";
			cin>>tempac;
			cout<<"\nENTER THE PASSWORD	    : ";
			cin>>pass;
			fin.open("Account.bin",ios::binary);
			if(!fin)
			cout<<"\nFILE NOT FOUND ";
			else
			{
				i=0;
				while(1)
				{
					fin.read((char*)&e,sizeof(e));
					if(fin.eof())
						break;
						if(e.getAcn()==tempac && e.getPass()==pass)
						{
							k++;
							int c;
			do
			{
			system("cls");
			cout<<"\n*****MENU****";
cout<<"\n1].DEPOSIT\n2].WITHDRAWAL\n3].TRANSFER MONEY\n4].ACCOUNT STATEMENT\n5].ACCOUNT DETAILS\n6].CHANGE PASSOWRD\n7].LOG OUT";
			cout<<"\nCHOICE  : ";
			cin>>c;
			switch(c)
			{
				case 1:
				{
					fin.close();
					float b;
					i=0;
					fin.open("Account.bin",ios::binary);
					if(!fin)
					cout<<"\nFILE NOT FOUND ";
					else
					{
					fout.open("acctemp.bin",ios::app|ios::binary);
					while(1)
					{
					fin.read((char*)&e,sizeof(e));
					if(fin.eof())
					break;
					if(e.getAcn()==tempac && e.getPass()==pass)
					{
					i++;
					b=e.deposit();
					if(b)
					{
					ffout.open("balance.txt",ios::app);
					time_t now=time(0);
					tm *d=localtime(& now);
					ffout<<e.getAcn()<<"\t\t"<<b<<"\t\t\t\t"<<e.getBalance()<<"\t\t";
					ffout<<d->tm_mday<<"-"<<1+d->tm_mon<<"-"<<1900+d->tm_year<<"\t";
					ffout<<d->tm_hour<<"-"<<d->tm_min<<"-"<<d->tm_sec<<endl;
					ffout.close();
													 	}									
											 		}
													fout.write((char*)&e,sizeof(e));
												}
												fout.close();
												fin.close();
												if(i==0)
													cout<<"\nACCOUNT NOT FOUND ";
												else
												{
												remove("Account.bin");
												rename("acctemp.bin","Account.bin");
												}
											}
										}
										break;
										case 2:
										{
											float b;
											fin.close();
											i=0;
											fin.open("Account.bin",ios::binary);
											if(!fin)
											cout<<"\nFILE NOT FOUND ";
											else
											{
												fout.open("acctemp.bin",ios::app|ios::binary);
												while(1)
												{
													fin.read((char*)&e,sizeof(e));
													if(fin.eof())
														break;
													if(e.getAcn()==tempac && e.getPass()==pass)
													{
														i++;
														b=e.withdraw();
														if(b)
														{
			ffout.open("balance.txt",ios::app);
			time_t now=time(0);
			tm *d=localtime(& now);
			ffout<<e.getAcn()<<"\t\t"<<"\t\t"<<b<<"\t\t"<<e.getBalance()<<"\t\t";
			ffout<<d->tm_mday<<"-"<<1+d->tm_mon<<"-"<<1900+d->tm_year<<"\t";
			ffout<<d->tm_hour<<"-"<<d->tm_min<<"-"<<d->tm_sec<<endl;
															ffout.close();
										 				}
												 	}
													fout.write((char*)&e,sizeof(e));
												}
												fout.close();
												fin.close();
												if(i==0)
													cout<<"\nACCOUNT NOT FOUND ";
												else
												{
													remove("Account.bin");
													rename("acctemp.bin","Account.bin");
												}
											}
										}
										break;
										case 3:
										{
										char s;
										int a,m=0;
										float b,tb;
										fin.close();
										TRY:
										cout<<"\nENTER THE DESTINATION ACCOUNT NUMBER :";
										cin>>a;
										if(a==tempac)
										{
										cout<<"\nFUNDS CAN'T BE TRANSFERED WITHIN SAME ACCOUNT :( \n";
										goto TRY;
										}
										fin.open("Account.bin",ios::binary);
										if(!fin)
										cout<<"\nFILE NOT FOUND";
										else
												{
													while(1)
													{
														fin.read((char*)&e,sizeof(e));
														if(fin.eof())
															break;
														if(e.getAcn()==a)
														{
															m++;
															cout<<"\nACCOUNT HOLDER NAME: ";
															e.putName();
															cout<<"\n";
														}
													}
													cout<<"\nDO YOU WANT TO CONTINUE  .?(Y/N) ";
													cin>>s;
													if(!(s=='Y' || s=='y'))
													{
														cout<<"\nVISIT AGAIN :}";
														goto EXIT;
													}
													fin.close();
													if(m!=0)
													{
													cout<<"\nENTER AMOUNT TO TRANSFER : ";
													cin>>tb;
														i=0;
														fin.open("Account.bin",ios::binary);
														fout.open("acctemp.bin",ios::app|ios::binary);
														while(1)
														{
															fin.read((char*)&e,sizeof(e));
															if(fin.eof())
																break;
															if(e.getAcn()==tempac && e.getPass()==pass)
															{
																i++;
														if(tb<=e.getBalance())
														{
														if(e.getType() =='S'|| e.getType()=='s')
														{
														if(a<=50000)
															goto CAN;
														else
														cout<<"\n\aSORRY, UNPERMITTED DEBIT *_* ";
														}
														else
														{
														if(tb<=100000)
														{
														CAN:
														b=e.getBalance();
														b-=tb;
														e.setBal(b);
														ffout.open("balance.txt",ios::app);
														time_t now=time(0);
														tm *d=localtime(& now);
											ffout<<e.getAcn()<<"\t\t"<<"\t\t"<<tb<<"\t\t"<<e.getBalance()<<"\t\t";
											ffout<<d->tm_mday<<"-"<<1+d->tm_mon<<"-"<<1900+d->tm_year<<"\t";
											ffout<<d->tm_hour<<"-"<<d->tm_min<<"-"<<d->tm_sec<<endl;
											ffout.close();
											}
											else
											{
												cout<<"\nSORRY, UNPERMITTED DEBIT";
											}
											}
										}
																else
																{
																	cout<<"\nINSUFFICIENT FUND ";
																}
													 		}
													 		fout.write((char*)&e,sizeof(e));
														}
														fout.close();
														fin.close();
														if(i!=0)
														{
															remove("Account.bin");
															rename("acctemp.bin","Account.bin");
														}
														else
															cout<<"\nFile not found ";
														//depositing to destination account..!
											i=0;
											fin.open("Account.bin",ios::binary);
											if(!fin)
												cout<<"\nFILE NOT FOUND ";
											else
											{
											fout.open("acctemp.bin",ios::app|ios::binary);
											while(1)
											{
											fin.read((char*)&e,sizeof(e));
											if(fin.eof())
											break;
											if(e.getAcn()==a)
											{
											i++;
											if(tb<=100000)
											{
											b=e.getBalance();
												b+=tb;
												e.setBal(b);
											cout<<"\n"<<tb<<" AMOUNT TRANSFERRED SUCCESSFULLY..!";
											ffout.open("balance.txt",ios::app);
											time_t now=time(0);
											tm *d=localtime(& now);
										ffout<<e.getAcn()<<"\t\t"<<tb<<"\t\t\t\t"<<e.getBalance()<<"\t\t";
										ffout<<d->tm_mday<<"-"<<1+d->tm_mon<<"-"<<1900+d->tm_year<<"\t";
										ffout<<d->tm_hour<<"-"<<d->tm_min<<"-"<<d->tm_sec<<endl;
										ffout.close();
											}
										else
										{
											cout<<"\n\nSORRY, UNPERMITTED CREDIT *_* ";
																		}
											 					}
																fout.write((char*)&e,sizeof(e));
															}
														}
														fout.close();
														fin.close();
														remove("Account.bin");
														rename("acctemp.bin","Account.bin");
													}
													else
													{
														cout<<"\nDESTINATION ACCOUNT NOT FOUND";
													}
												}
												EXIT:
													cout<<"\n";
											}
										break;
										case 4:
										{
											fin.close();
											int acn;
											char str[80];
											float cbal,bal;

											cout<<"\n";
											fin.open("balance.txt",ios::binary);
											if(!fin)
												cout<<"\nFILE NOT FOUND ";
											else
											{
												i=0;
												int pos;
												while(1)
												{
													pos=fin.tellg();
													fin>>acn;
													if(fin.eof())
													{
														break;
													}
										if(acn==tempac)
										{
										if(i==0)
									{
							cout<<"\n***************Transaction Details***************";
						cout<<"\nAccount No.\tCredit\t\tDebit\t\tBalance\t\tDate\t\tTime\n\n";
							}
								i++;
								fin.seekg(pos,ios::beg);
							fin.getline(str,80);
												cout<<"\n"<<str;
													}
												}
												if(i==0)
												cout<<"\nACCOUNT NOT FOUND ";
											}
											fin.close();
										}
										break;
										case 5:
										{
											fin.close();
											fin.open("Account.bin",ios::binary);
											if(!fin)
												cout<<"\nFILE NOT FOUND  \n";
											else
											{
												i=0;
												while(1)
												{
													fin.read((char*)&e,sizeof(e));
													if(fin.eof())
													{
														break;
													}
													if(e.getAcn()==tempac && e.getPass()==pass)
													{
														i++;
														e.display();
														break;
													}
												}
												if(i==0)
													cout<<"\nACCOUNT NOT FOUND ";
											}
											fin.close();
										}
										break;
										case 6:
										{
											fin.close();
											int opass,p=0,j=0,n,r;
											ENTR:
											cout<<"\nENTER THE OLD PASSWORD ";
											cin>>opass;
											n=opass;
											while(n!=0)
											{
												r=n%10;
												j++;
												n=n/10;
											}
											if(j!=6)
											{
												cout<<"\n\aPLEASE ENTER VALID PASSWORD..! \n";
												j=0;
												goto ENTR;
											}
											fin.open("Account.bin",ios::binary);
											fout.open("passtem.bin",ios::binary|ios::app);
											if(fin)
											{
												while(1)
												{
													fin.read((char *)&e,sizeof(e));
													if(fin.eof())
														break;
													if(e.getPass()==opass)
													{
														p++;
														e.changepass();
													}
													fout.write((char*)&e,sizeof(e));
												}
											}
											else
											cout<<"\nFILE NOT FOUND ";
											fin.close();
											fout.close();
											if(p!=0)
											{
												remove("Account.bin");
												rename("passtem.bin","Account.bin");
											}
											else
											{
												cout<<"\nACCOUNT NOT FOUND ";
											}
										}
										break;
										case 7:	cout<<"\nTHANK YOU..! :) ";
										break;
										default:	cout<<"\n\aINVALID INPUT :{";
											break;
									}
									getch();
								}while(c!=7);
							}
						}
						fout.close();
						fin.close();
						if(k==0)
						cout<<"\nACCOUNT IS NOT FOUND ";
					}
				}
				break;
				case 2:
				{
					int j,m;
					again:
					fin.open("Account.bin",ios::binary);
					cout<<"\nENTER ACCOUNT NUMBER : ";
					cin>>tempac;
					if(fin!=NULL)
					{
						j=0;
						m=0;
						while(1)
						{
							fin.read((char*)&e,sizeof(e));
							if(fin.eof())
								break;
							if(e.getAcn()==tempac)
							{
								j++;
								break;
							}
						}
						fin.close();
						
						fin.open("delete.txt",ios::binary);
						
						while(1)
						{
							fin>>ano;
							
							if(fin.eof())
							    break;
							if(tempac==ano)
							{
								m++;
								break;
							}
						}
						fin.close();												
						
						
						if(j==0 && m==0)
							goto get;
						else
						{
							cout<<"\nAccount alreay exist \n";
							goto again;
						}
					}
					else
					{
						get:
						fout.open("Account.bin",ios::app|ios::binary);
						e.setAcn(tempac);
						e.getData();
						fout.write((char*)&e,sizeof(e));
						fout.close();

						ffout.open("balance.txt",ios::app);
						time_t now=time(0);
						tm *d=localtime(& now);
						ffout<<e.getAcn()<<"\t\t"<<e.getBalance()<<"\t\t\t\t"<<e.getBalance()<<"\t\t";
						ffout<<d->tm_mday<<"-"<<1+d->tm_mon<<"-"<<1900+d->tm_year<<"\t";
						ffout<<d->tm_hour<<"-"<<d->tm_min<<"-"<<d->tm_sec<<endl;
						ffout.close();
					}
				}
				break;
				case 3:
				{
						int f=0,g;
					
					cout<<"\nENTER THE ACCOUNT NUMBER : ";
					cin>>tempac;
					cout<<"\nENTER THE PASSWORD : ";
					cin>>pass;
					
					ano=tempac;
				
					fin.close();
				
					
							fout.open("acctemp.bin",ios::binary);
				        	fin.open("Account.bin",ios::binary);
				        	if(!fin)
					    	cout<<"\nFILE DOES NOT EXIST ";
				         	else
				           	{
					        
					         	while(1)
					        	{
					        		fin.read((char*)&e,sizeof(e));
					            		if(fin.eof())
					          			break;
					           		if(e.getAcn()==tempac && e.getPass()==pass)
					           		{
									    
					          		   f=1;
					          	    }
					          		else
					         		fout.write((char*)&e,sizeof(e));
					     	    }
					            	fin.close();
					             	fout.close();
					             	remove("Account.bin");
					             	rename("acctemp.bin","Account.bin");
					       
						    }
						if(f==0)
							cout<<"\nSORRY, ACCOUNT DOES NOT EXIST ";
						else
						{
						    fout.open("delete.txt",ios::binary|ios::app);
						    fout<<ano<<"\n";
						    fout.close();
						    
						    cout<<"\nACCOUNT DELETED SUCCESSFULLY..!";
					    }
					
				}
				break;
				case 4:
				{
					int a,pass,i=0;
					
					workHard:
						
					cout<<"\nENTER THE ADMINSTRATOR PASSWORD : ";
					cin>>pass;
					
				 if(pass==1221)
		      	{
					
					do
					{
						system("cls");
						cout<<"\n**MENU**";
						cout<<"\n1).ACCOUNT HOLDER'S LIST\n2).BANK STATEMENT\n3).EXIT\n";
						cout<<"\nCHOICE: ";
						cin>>a;
						switch (a)
						{
							case 1:
							{
								fin.open("Account.bin",ios::binary);
								if(fin)
								{
									while(1)
									{
										cout<<"\n";
										fin.read((char*)&e,sizeof(e));
										if(fin.eof())
											break;
										e.display();
									}
								}
								else
								{
									cout<<"\nFILE NOT FOUND ";
								}
								fin.close();
							}
							break;
							case 2:
							{
								char ch;
								fin.open("balance.txt");
								if(!fin)
								{
									cout<<"\nFile is not Found \n";
								}
								else
								{
					cout<<"\nAccount No.\tCredit\t\tDebit\t\tBalance\t\tDate\t\tTime\n";
									while(1)
									{
										ch=fin.get();
										if(fin.eof())
											break;
										cout<<ch;
									}
								}
								fin.close();
							}
							break;
							case 3:cout<<"\nGOOD BYE :) \n";break;
							deafult:cout<<"\nINVALID CHOICE ";
						}
						getch();
					}while(a!=3);
				}
				else
				{
					i++;
					while(i<3)
					{
					   	cout<<"\n\a# WRONG PASSWORD :(";
					   	cout<<"\nYOU HAVE "<<3-i<<" CHANCES LEFT !";
					   	cout<<"\nPLEASE TRY AGAIN *_*\n ";
						   goto workHard;
					}
					if(i==3)
					{ 
					     cout<<"\nYOU HAVE COMPLETED YOUR 3 ATTEMPTS UNSUCCESSFULLY..!! \n";
					     cout<<"\nYOU CAN'T LOG IN NOW..!\nPLEASE TRY AGAIN AFTER SOME TIME..:( ";
						break;
					 }
					  	
				}
				}
				break;
				case 5:cout<<"\nTHANK YOU FOR USING BANK ACCOUNT PROJECT..! :)\n";
				break;
				default:cout<<"\n\aINVALID SELECTION :(";
		}
		getch();
	}while(choice!=5);
return 0;
}



