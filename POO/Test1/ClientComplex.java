class Complex{
    private double re, im;
    static int cnt=0;
    public Complex(double r, double i){
	re=r;
	im=i;
    }
    public double modul(){
	return Math.sqrt(re*re+im*im);
    }
    public Complex suma(Complex a){
	Complex s=new Complex(this.re+a.re, this.im+a.im);
	return s;
    }
    public void afiseaza(){
	System.out.println(re + " + i*(" + im + ")");
	cnt++;
    }
}

public class ClientComplex{
    public static void main(String[] args)
    {
	Complex c1=new Complex(3,2);
	Complex c2=new Complex(1,2);
	c1.afiseaza();
	c2.afiseaza();
	System.out.println("Modul :" + c1.modul());
	Complex s=c1.suma(c2);
	s.afiseaza();
	System.out.println("Numarul de afisari: " + Complex.cnt);
    }
}



