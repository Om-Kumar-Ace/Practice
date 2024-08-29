

public class B003 {
    public static void main(String[] args) {
        
        System.out.println("Enter Salary:");
        // Scanner input salary = new Scanner(System.in); 
        float salary =200000;
        if (salary<2000.00) {
            salary=salary+100;
        }
        else{
            
            salary=salary+200;
        }
        System.err.println(salary);
    }
}
