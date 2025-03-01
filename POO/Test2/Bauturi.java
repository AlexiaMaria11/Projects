import java.util.*;

abstract class Whiskey{
    protected String nume;
    public Whiskey(String nume){
	this.nume=nume;
    }
    abstract double getNrCalorii(double ml);
    abstract double getConcentratieAlcool();
}

abstract class WhiskeySimplu extends Whiskey{
    private double alcool;
    public WhiskeySimplu(String nume, double alcool){
	super(nume);
	this.alcool=alcool;
    }
    public double getConcentratieAlcool(){
	return alcool;
    }
}

class ClassicWhiskey extends WhiskeySimplu{
    public ClassicWhiskey(String nume, double alcool){
	super(nume, alcool);
    }
    public double getNrCalorii(double ml){
	return getConcentratieAlcool()*ml*5;
    }
    public String toString(){
	return nume + ", Concentratie alcool: " + getConcentratieAlcool() + "%, Calorii pe 100ml: " + getNrCalorii(100.0);
    }
}

class JackAndHoney extends WhiskeySimplu{
    private int indulcitor;
    public JackAndHoney(String nume, double alcool, int indulcitor){
	super(nume, alcool);
	this.indulcitor = indulcitor;
    }
    public double getNrCalorii(double ml){
	return (getConcentratieAlcool()*ml*5 + indulcitor*ml*15);
    }
    public String toString(){
	return nume + ",Concentratie alcool: " + getConcentratieAlcool() + "%, Calorii pe 100 ml: " + getNrCalorii(100.0) + ", Cantitate indulcitor: " + indulcitor;
    }
}

class BlendedWhiskey extends Whiskey{
    private List<Whiskey> bauturi = new ArrayList<Whiskey>();
    public BlendedWhiskey(String nume){
	super(nume);
    }
    public void addWhiskey(Whiskey w){
	bauturi.add(w);
    }
    public double getConcentratieAlcool(){
	double s=0.0;
	int c=0;
	Iterator<Whiskey> it = bauturi.iterator();
	while(it.hasNext()){
	    c++;
	    s+=it.next().getConcentratieAlcool();
	}
	return s/((double)c);
    }
    public double getNrCalorii(double ml){
	double s=0.0;
	int c=0;
	Iterator<Whiskey> it = bauturi.iterator();
	while(it.hasNext()){
	    c++;
	    s+=it.next().getNrCalorii(ml);
	}
	return s/((double)c);
    }
    public String toString(){
	String s=nume + ", Concentratie alcool: " + getConcentratieAlcool()+ "%, Calorii pe 100 ml: " + getNrCalorii(100.0) + ",\nCompozitie: ";
	Iterator<Whiskey> it = bauturi.iterator();
	int c=0;
	while(it.hasNext()){
	    c++;
	    s+="Whiskey" + c + "-" + it.next();
	    if(it.hasNext()) s+="\n";
	}
	return s;
    }
}

class Bauturi{
    public static void main(String args[]){
	Whiskey w1, w2, w3, w4, w5, w6;
	w1 = new ClassicWhiskey("Clasic", 10.0);
	w2 = new JackAndHoney("Jack", 13.5, 4);
	
	w3 = new ClassicWhiskey("Cla", 12.3);
	w4 = new ClassicWhiskey("Cic", 14.7);
	w5 = new BlendedWhiskey("Blend");
	((BlendedWhiskey)w5).addWhiskey(w3);
	((BlendedWhiskey)w5).addWhiskey(w4);
	
	w6 = new BlendedWhiskey("Mix");
	((BlendedWhiskey)w6).addWhiskey(w1);
	((BlendedWhiskey)w6).addWhiskey(w2);
	((BlendedWhiskey)w6).addWhiskey(w5);
	System.out.println(w6);
	System.out.println(w6.getNrCalorii(150));
    }
}
