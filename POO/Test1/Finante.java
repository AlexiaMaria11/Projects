class Card{
    private String numar;
    private float sold;
    public Card(String nr, float s){
	numar=nr;
	sold=s;
    }
    public String getNumar(){
	return numar;
    }
    public String toString(){
	return numar + " - " + sold + "; ";
    }
    public float getSold(){
	return sold;
    }
}

class Portofel{
    private String nume;
    private Card[] carduri = new Card[6];
    private int contor=0;
    public Portofel(String n){
	nume=n;
    }
    private boolean cautaCard(String nu){
	for(int i=0; i<contor; i++)
	    if(carduri[i].getNumar()==nu)
		return true;
	return false;
    }
    public boolean adaugaCard(String nu, float nr){
	if(contor<6 && !(this.cautaCard(nu))){
	    carduri[contor] = new Card(nu, nr);
	    contor++;
	    return true;
	}
	System.out.println("Nu s-a adaugat cardul");
	return false;
    }
    public String toString(){
	String rez="Portofel " + nume + ": ";
	for (int i=0; i<contor; i++)
	    rez+=carduri[i];
	return rez;
    }
    public float calculeazaSold(){
	float s=0;
	for(int i=0; i<contor; i++)
	    s+=carduri[i].getSold();
	return s;
    }
}

class Finante{
    public static void main(String[] args){
	Portofel p = new Portofel("Alexia");
	p.adaugaCard("1234567", 3000);
	p.adaugaCard("1357", 2000);
	p.adaugaCard("2468", 1000);
	p.adaugaCard("1357", 2500);
	System.out.println(p);
	System.out.println(p.calculeazaSold());
    }
}
