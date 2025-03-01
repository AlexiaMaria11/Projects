import java.util.*;

abstract class Autovehicul{
    protected String numar;
    protected double greutate;
    public Autovehicul(String numar, double greutate){
	this.numar=numar;
	this.greutate=greutate;
    }
    abstract double calculeazaGreutateTotala();
}

class Autoturism extends Autovehicul{
    private double pasageri;
    public Autoturism(String numar, double greutate, double pasageri){
	super(numar, greutate);
	this.pasageri=pasageri;
    }
    public double calculeazaGreutateTotala(){
	return greutate + pasageri;
    }
    public String toString(){
	return "Numar inmatriculare: " + numar + ", Greutate autovehicul: " + greutate + ", Greutate pasageri: " + pasageri;
    }
}

class Camion extends Autovehicul{
    private List<Autoturism> auto = new ArrayList<Autoturism>();
    public Camion(String numar, double greutate){
	super(numar, greutate);
    }
    public void adaugaAutoturism(Autoturism a){
	auto.add(a);
    }
    public double calculeazaGreutateTotala(){
	double s=greutate;
	Iterator<Autoturism> it = auto.iterator();
	while(it.hasNext()){
	    s+=it.next().calculeazaGreutateTotala();
	}
	return s;
    }
    public String toString(){
	int c=0;
	String s = "Numar inmatriculare: " + numar + ", Greutate autovehicul: " + greutate + ", (";
	Iterator<Autoturism> it = auto.iterator();
	while(it.hasNext()){
	    c++;
	    s+="Autoturism" + c + " - " + it.next();
	    if(it.hasNext()) s+=", ";
	}
	s+=")";
	return s;
    }
}

class Bac{
    private double maxim, curent=0.0;
    private List<Autovehicul> a = new ArrayList<Autovehicul>(); 
    public Bac(double m){
	maxim=m;
    }
    public boolean adaugaAutovehicul(Autovehicul au){
	curent+=au.calculeazaGreutateTotala();
	if(curent<=maxim){
	    a.add(au);
	    return true;
	}
	else
	    return false;
    }
    public String toString(){
	String s="Greutate maxima: " + maxim + ": (";
	Iterator<Autovehicul> it = a.iterator();
	int c=0;
	while(it.hasNext()){
	    c++;
	    s+="Autovehicul" + c + "-" + it.next();
	    if(it.hasNext()) s+=", ";
	}
	s+=")";
	return s;
    }
}

class Transport{
    public static void main(String args[]){
	Autovehicul a1, a2, a3;
	a1 = new Autoturism("TM01DOA", 4.0, 0.3);
	a2 = new Autoturism("BH08XTX", 5.0, 0.25);
	a3 = new Autoturism("AR17RUN", 4.5, 0.15);
	Autovehicul c = new Camion("B123CAM", 10.0);
	((Camion)c).adaugaAutoturism((Autoturism)a1);
	((Camion)c).adaugaAutoturism((Autoturism)a2);
	Bac b = new Bac(20);
	if(b.adaugaAutovehicul(c))
	    System.out.println("S-a adaugat in bac");
	else
	    System.out.println("Nu s-a adaugat");
        if(b.adaugaAutovehicul(a3))
	    System.out.println("S-a adaugat in bac");
	else
	    System.out.println("Nu s-a adaugat");
	System.out.println(b);
    }
}
