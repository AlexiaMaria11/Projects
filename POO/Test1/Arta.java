class Figura{
    private double arie;
    public Figura(double a){
	arie=a;
    }
    public String toString(){
	return "Figura - " + arie + "; ";
    }
    public double getArie(){
	return arie;
    }
}

class Desen{
    private String titlu;
    private Figura[] figuri = new Figura[1024];
    private int contor=0;
    public Desen(String t){
	titlu=t;
    }
    private boolean cautaFigura(Figura f){
	for(int i=0; i<contor; i++)
	    if(figuri[i]==f)
		return true;
	return false;
    }
    public boolean adaugaFigura(Figura f){
	if(contor<1024 && !(cautaFigura(f))){
	    figuri[contor]=f;
	    contor++;
	    return true;
	}
	System.out.println("Nu s-a adaugat figura");
	return false;
    }
    private double sumaArie(){
	double s=0;
	for(int i=0; i<contor; i++)
	    s+=figuri[i].getArie();
	return s;
    }
    public double medieArie(){
	if(contor==0)
	    return 0;
	return sumaArie()/contor;
    }
    public String toString(){
	String rez = titlu + ": ";
	for(int i=0; i<contor; i++)
	    rez+=figuri[i];
	return rez;
    }
}

class Arta{
    public static void main(String[] args){
	Desen d = new Desen("Vaza cu flori");
	Figura f1 = new Figura(21.0);
	Figura f2 = new Figura(11.1);
	Figura f3 = new Figura(8.4);
	d.adaugaFigura(f1);
	d.adaugaFigura(f2);
	d.adaugaFigura(f3);
	d.adaugaFigura(f2);
	System.out.println(d);
	System.out.println(d.medieArie());
    }
}
