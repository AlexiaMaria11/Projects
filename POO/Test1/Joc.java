class Jucator{
    private String nume;
    private int numar;
    public Jucator(String n, int nr){
	nume=n;
	numar=nr;
    }
    public boolean equals(Object o){
	if(o instanceof Jucator){
	    Jucator other = (Jucator)o;
	    return (other.nume==this.nume) && (other.numar==this.numar);
	}
	return false;
    }
    public String toString(){
	return "(" + nume + "," + numar + ") ";
    }
}

class Echipa{
    private Jucator[] titulari = new Jucator[11];
    private Jucator[] rezerve = new Jucator[5];
    public Echipa(Jucator[] t, Jucator[] r){
	for(int i=0; i<11; i++){
	    titulari[i] = t[i];
	}
	for(int i=0; i<5; i++){
	    rezerve[i]=r[i];
	}
    }
    private int cautaJucatorTitular(Jucator j){
	for(int i=0; i<11; i++)
	    if(titulari[i].equals(j))
		return i;
	return -1;
    }
    private int cautaJucatorRezerva(Jucator j){
	for(int i=0; i<5; i++)
	    if(rezerve[i].equals(j))
		return i;
	return -1;
    }
    public boolean efectueazaSchimbare(Jucator t, Jucator r){
	if(cautaJucatorTitular(t)!=-1 && cautaJucatorRezerva(r)!=-1){
	    int it=cautaJucatorTitular(t), ir=cautaJucatorRezerva(r);
	    titulari[it]=r; rezerve[ir]=t;
	    return true;
	}
	return false;
    }
    public String toString(){
	String rez="Titulari: ";
	for(int i=0; i<11; i++)
	    rez+=titulari[i];
	rez+="Rezerve: ";
	for(int i=0; i<5; i++)
	    rez+=rezerve[i];
	return rez;
    }
}

class Joc{
    public static void main(String[] args){
	Jucator[] t = new Jucator[11];
	t[0]=new Jucator("Messi", 11);
	t[1]=new Jucator("Ronaldo",7);
	t[2]=new Jucator("Hagi", 12);
	t[3]=new Jucator("Tamas", 1);
	t[4]=new Jucator("Pepe", 3);
	t[5]=new Jucator("Dragusin", 5);
	t[6]=new Jucator("Lewandowski", 10);
	t[7]=new Jucator("Mbappe", 4);
	t[8]=new Jucator("Kane", 2);
	t[9]=new Jucator("Neymar", 6);
	t[10]=new Jucator("Moldovan", 8);
	Jucator[] r = new Jucator[5];
	r[0]=new Jucator("Nita", 20);
	r[1]=new Jucator("Ratiu", 15);
	r[2]=new Jucator("Manea", 13);
	r[3]=new Jucator("Bancu", 18);
	r[4]=new Jucator("Burca", 19);
	Echipa e = new Echipa(t, r);
	System.out.println(e);
	e.efectueazaSchimbare(t[5], r[3]);
	System.out.println(e);
    }
}
