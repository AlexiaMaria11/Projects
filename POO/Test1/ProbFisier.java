class Fisier{
    private String nume;
    private String continut;
    private static int id=0;
    private int idc;
    private int cnt=0;
    private Fisier anterior=null;
    
    public Fisier(String nu, String co){
	nume=nu;
	continut=co;
        anterior=null;
	id++;
	idc=id;
    }
    public Fisier salveazaVersiune(){
	Fisier ne=new Fisier(nume+"bak", continut);
	ne.anterior=this.anterior;
	this.anterior=ne;
	return ne;
    }
    public void concateneaza(Fisier f){
	this.salveazaVersiune();
	this.continut=this.continut+" "+f.continut;
	cnt++;
    }
    public String toString(){
	if(this.anterior!=null)
	    return "id: " + idc + " Nume: " + nume + " Continut: " + continut + " Continut anterior: " + anterior.continut;
	else
	    return "id: " + idc + " Nume: " + nume+" Continut: "+continut;
    }
    public int numarConcatenari(){
	return cnt;
    }
}

public class ProbFisier{
    public static void main(String[] args){
	Fisier f1=new Fisier("pizza", "cea mai buna pizza e cu mascarpone");
	Fisier f2=new Fisier("bmw", "cea mai buna masina");
	System.out.println(f1);
	System.out.println(f2);
	Fisier f3=null;
	f3=f1.salveazaVersiune();
	System.out.println(f3);
	f1.concateneaza(f2);
	f1.concateneaza(f3);
	System.out.println(f1);
	System.out.println("Numar concatenari: " + f1.numarConcatenari());
    }
}
