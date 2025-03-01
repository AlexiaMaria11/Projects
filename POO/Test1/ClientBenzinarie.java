class Masina{
    private String nr_inmatriculare;
    private int litrii;
    public Masina(String nr, int li){
	nr_inmatriculare=nr;
	litrii=li;
    }
    public int getLitrii(){
	return litrii;
    }
    public String toString(){
	return nr_inmatriculare + " - " + litrii + " ; ";
    }
}

class Benzinarie{
    private int cantitate, contor=0;
    private Masina[] masini =new Masina[10];
    public boolean alimenteazaMasina(Masina m){
	if(cantitate - m.getLitrii() >= 0)
	    {
		cantitate=cantitate-m.getLitrii();
		return true;
	    }
	if(contor<10)
	    {
		masini[contor]=m;
		contor++;
		return true;
	    }
	System.out.println("Nu s-a alimentat masina");
	return false;
    }
    public String toString(){
	String rez="Coada benzinarie: ";
	for(int i=0; i<contor; i++)
	    rez+=masini[i];
	return rez;
    }
    public void alimenteazaBenzinarie(int c){
	cantitate+=c;
	for(int i=0; i<contor && contor >=0; i++){
	    if(cantitate - masini[i].getLitrii() >= 0)
		{
		    this.alimenteazaMasina(masini[i]);
		    for(int j=i; j<contor-1; j++)
			masini[j]=masini[j+1];
		    contor--;
		    i--;
		}
	    else
		return;
	}
    }
}

class ClientBenzinarie{
    public static void main(String [] args){
	Benzinarie b = new Benzinarie();
	Masina m1 = new Masina("TM01DOA", 5);
	Masina m2 = new Masina("AR17RUN", 10);
	Masina m3 = new Masina("BH08XTX", 15);
	b.alimenteazaMasina(m1);
	b.alimenteazaMasina(m2);
	b.alimenteazaMasina(m3);
	System.out.println(b);
	b.alimenteazaBenzinarie(15);
	System.out.println(b);
    }
}
