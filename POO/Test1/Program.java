public class Program{
    public static void main(String[] args){
	System.out.println("Hello world");
	int a=5, b=10, s=0;
	if(a>b)
	    System.out.println("Valoarea maxima este: " + a);
	else
	    System.out.println("Valoarea maxima este: " + b);
	for(int i=1; i<=100; i++){
	    if(i%2==0)
		s=s+i;
	    else
	        System.out.print(i + " ");	
	}
	System.out.println("\nSuma este: " + s);
    }
}
