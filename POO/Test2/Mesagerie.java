import java.util.*;

abstract class Destinatar{
    protected String nume;
    protected Destinatar(String n){
	nume=n;
    }
    abstract void receptioneaza(Utilizator u, String s);
    public boolean equals(Object d){
	if(d==null) return false;
	if(d instanceof Destinatar)
	    return this.nume.equals(((Destinatar)d).nume);
	return false;
    }
}

class Utilizator extends Destinatar{
    private String jurnal;
    public Utilizator(String nume){
	super(nume);
	jurnal="";
    }
    public void trimite(Destinatar d, String mesaj){
	jurnal+="Trimis catre " + d.nume + " mesajul: " + mesaj + "\n";
	d.receptioneaza(this, mesaj);
    }
    public void receptioneaza(Utilizator u, String s){
	jurnal+="Primit de la " + u.nume + " mesajul: " + s + "\n";
    }
    public String toString(){
	return nume + ":\n" + jurnal;
    }
}

class DestinatarDuplicat extends Exception{
    public DestinatarDuplicat(){
	super("Destinatar duplicat");
    }
}

class Grup extends Destinatar{
    private List<Destinatar> destinatari = new ArrayList<Destinatar>();
    public Grup(String nume){
	super(nume);
    }
    public void inscrie(Destinatar d) throws DestinatarDuplicat{
	for(Destinatar i:destinatari){
	    if(i.equals(d))
		throw new DestinatarDuplicat();
	}
	destinatari.add(d);
    }
    public void receptioneaza(Utilizator u, String s){
	for(Destinatar i:destinatari){
	    if(i.equals(u)==false){
		i.receptioneaza(u, s);
	    }
	}
    }
}

class Mesagerie{
    public static void main(String args[]){
	Utilizator d1,d2,d3;
	d1 = new Utilizator("Dan");
	d2 = new Utilizator("Marius");
	d3 = new Utilizator("Alex");
	Grup g = new Grup("Carnivorii");
	try{
	    ((Grup)g).inscrie(d1);
	}catch(DestinatarDuplicat e){
	    System.out.println(e.getMessage());
	}
	try{
	    ((Grup)g).inscrie(d2);
	}catch(DestinatarDuplicat e){
	    System.out.println(e.getMessage());
	}
      	try{
	    ((Grup)g).inscrie(d3);
	}catch(DestinatarDuplicat e){
	    System.out.println(e.getMessage());
	}
	try{
	    ((Grup)g).inscrie(d3);
	}catch(DestinatarDuplicat e){
	    System.out.println(e.getMessage());
	}
	(d3).trimite(g, "Am deschis magazinul");
	(d2).trimite(g, "Vin acuma");
	System.out.print(d1);
	System.out.print(d2);
	System.out.print(d3);
    }
}
