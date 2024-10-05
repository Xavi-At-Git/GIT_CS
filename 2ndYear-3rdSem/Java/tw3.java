import java.util.Scanner;
public class tw3 {

static class mybankAccount{
    static int accNo;
    String accType, name, address;
    double accBal;
    static int count=0;

    mybankAccount(){
        Scanner sc = new Scanner(System.in);
        accNo = ++count;
        System.out.println("Enter your name: ");
        name = sc.nextLine();
        System.out.println("Enter the address: ");
        address = sc.nextLine();
        System.out.println("Enter the account type: ");
        accType = sc.nextLine();
        System.out.println("Enter the account balance: ");
        accBal = sc.nextDouble();
    }
    mybankAccount(String name, String accType, String address, double accBal){
        accNo = ++count;
        this.name = name;
        this.accType = accType;
        this.address = address;
        this.accBal = accBal;
    }
    void computeInt(int time){
        double interest=0.0;
        if("SB".equals(accType))
            interest = accBal*time*0.05;
        else if("RD".equals(accType))
            interest = accBal*time*0.065;
        else if("FD".equals(accType))
            interest = accBal*time*0.0765;
        else{
            System.out.println("Invalid account type");
            System.exit(0);
        }
        System.out.println("The interest computed is "+interest);
        accBal += interest;
        System.out.println("The account balance after adding the interest "+accBal);
    }
    void deposit(double amount){
        accBal += amount;
        System.out.println("The balance after the deposit "+accBal);
    }
    void withdraw(double amount){
        if((accBal-amount)<1000)
            System.out.println("Insufficient Balance");
        else{
            accBal -=amount;
            System.out.println("The balance after the withdrawl "+accBal);
        }
    }
    void display(){
        System.out.println("The customer details are: ");
        System.out.println("Name: "+name);
        System.out.println("Address: "+address);
        System.out.println("Account Type: "+accType);
        System.out.println("Accont Number: "+accNo);
        System.out.println("Account Balance: "+accBal);
    }
}
    public static void main(String[] args) {
        System.out.println("-------For the default constructor--------");
        mybankAccount a1 = new mybankAccount();
        a1.computeInt(2);
        a1.deposit(1000);
        a1.withdraw(200);
        a1.display();

        System.out.println("-------For the parameterized constructor--------");
        mybankAccount a2 = new mybankAccount("Akshay","FD","Belagavi",20000);
        a2.computeInt(1);
        a2.deposit(2000);
        a2.withdraw(100);
        a2.display();

        mybankAccount a3 = new mybankAccount("Shankar","RD","Belagavi",25000);
        a3.computeInt(2);
        a3.deposit(5000);
        a3.withdraw(500);
        a3.display();
    }
}