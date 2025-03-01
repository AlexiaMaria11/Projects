import java.util.*;

abstract class Utilizator{
    protected String nume;
    public Utilizator(String nume){
	this.nume=nume;
    }
    abstract double calculeazaVenit(int minute);
}

class Subscriber extends Utilizator{
    private int nivel;
    public Subscriber(String nume, int nivel){
	super(nume);
	this.nivel=nivel;
    }
    public double calculeazaVenit(int minute){
	return 1.5 * (double)nivel * minute;
    }
    public String toString(){
	return nume + " - subscriber - " + nivel;
    }
}

class Creator extends Utilizator{
    private List<Subscriber> subs = new ArrayList<Subscriber>();
    public Creator(String nume){
	super(nume);
    }
    public void adaugaSubscriber(Subscriber s){
	subs.add(s);
    }
    public double calculeazaVenit(int minute){
	Iterator<Subscriber> it = subs.iterator();
	double d=0.0;
	while(it.hasNext()){
	    d+=it.next().calculeazaVenit(minute);
	}
	return d;
    }
    public String toString(){
	String s= nume + " - creator - subscriberi: ";
	Iterator<Subscriber> it = subs.iterator();
	while(it.hasNext()){
	    s+=it.next();
	    if(it.hasNext())
		s+=", ";
	}
	return s+"\n";
    }
}

class Platforma{
    private Utilizator[] u = new Utilizator[1000];
    private int nr_utilizatori=0;
    public boolean adaugaUtilizator(Utilizator ut){
	if(nr_utilizatori<1000){
	    u[nr_utilizatori] = ut;
	    nr_utilizatori++;
	    return true;
	}
	else
	    return false;
    }
    public Utilizator determinaVIP(int minute){
	double maxim = 0;
	if(nr_utilizatori==0)
	    return null;
	Utilizator um = u[0];
	for(int i=1; i<nr_utilizatori; i++){
	    if(u[i].calculeazaVenit(minute)>maxim){
		maxim = u[i].calculeazaVenit(minute);
		um=u[i];
	    }
	}
	return um;
    }
    public String toString(){
	String s="";
	for(int i=0; i<nr_utilizatori; i++)
	    s+=u[i];
	return s;
    }
}

class Twitch{
    public static void main(String args[]){
	Platforma p = new Platforma();
	Utilizator u1 = new Subscriber("Angela", 2);
	Utilizator u2 = new Subscriber("Mihai", 1);
	Utilizator u3 = new Subscriber("Ana", 4);
	Utilizator u4 = new Subscriber("Ion", 3);
	Utilizator u5 = new Subscriber("Maria", 2);
	Utilizator u6 = new Subscriber("Bogdan", 1);
	Utilizator u7 = new Creator("Ioana");
	((Creator)u7).adaugaSubscriber((Subscriber)u1);
	((Creator)u7).adaugaSubscriber((Subscriber)u2);
	Utilizator u8 = new Creator("Andrei");
	((Creator)u8).adaugaSubscriber((Subscriber)u3);
        ((Creator)u8).adaugaSubscriber((Subscriber)u4);
        ((Creator)u8).adaugaSubscriber((Subscriber)u5);
	p.adaugaUtilizator(u7);
	p.adaugaUtilizator(u8);
	p.adaugaUtilizator(u6);
	System.out.println(p);
	System.out.print("Utilizatorul VIP: " + p.determinaVIP(30));
    }
}
