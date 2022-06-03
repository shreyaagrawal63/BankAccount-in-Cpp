# BankAccount-in-Cpp
This project can create and maintain several bank accounts with many features
The bank account project has several features like creating new
account opening existing account, deleting account, and
administrator login, etc.
A) Open existing account: In the opening existing account section we have seven choices including log-out mechanism for specific logged In account. The choices are as follows:
  i. Deposition: A deposit is a transaction involving a transfer of money from account holder to its account held by Bank. To deposit an amount in our account we use        deposition. Its task is to accept the amount to be deposited and if it satisfies certain criteria of bank (i. e. The amount given by account holder should be            less than bank’s creditable limit), then amount will be deposited (i.e. current balance will be incremented by that amount).
  
  ii. Withdrawal: A withdrawal involves removing funds from a bank account. Or removing fund from an account is called withdrawal. Its task is to accept the amount to     be withdrawn and then it compares the current balance and amount (given by user). If it is less than current balance then control processes further and then after       it satisfies certain criteria of bank, the amount will be withdrawn (i.e.the current balance will be deducted by the amount).
    
  iii. Transfer: "Transfer" is a shortcut for entering a deposit and a withdrawal with one entry. Do not need to createone withdrawal (from one account plus one deposit   (in another account). You can do this in one step. It refers to the act of withdrawing from one Account and depositing to other. Its task is to accept destination       account number and then it checks for the satisfaction of validation of account, if satisfied then control moves ahead and by checking all required conditions for       withdrawal as well as for deposit. If all conditions are met then it successfully transfers the balance from one account to another.
    
   iv. Account Statement: It enlists the transaction details ofparticular account by displaying column wise data ofaccount number, credit, debit, current balance, date      and time for each such transaction made includes debit credit and transfer funds etc.
  
  v. Account Details: Its task is to display data of particular account by fetching data from file (Input from file).

  vi. Change password: It modifies the old password after confirmation of account holder which has two step verification. After changing password when the account holder   begin again he will have to give new password .Old one will be vanished and if he gives the same, it will make no sense because password has been already modified
  
  vii.Log out: Once you logged out from particular accountthen to log in again it will be mandatory for user toprovide valid account number with password else you will
  not able to log in. Its main task is to log out the account
