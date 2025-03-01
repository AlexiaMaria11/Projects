class Angajat{
    private String nume;
    private int salariu;
    public Angajat(String nu, int sal){
	nume=nu;
	salariu=sal;
    }
    public int getSalariu(){
	return salariu;
    }
    public String toString(){
	return "Angajat " + nume + " - " + salariu + "; ";
    }
}

class Firma{
    private String nume;
    private int buget, index=0;
    private Angajat[] angajati=new Angajat[30];
    public Firma(String nu, int bu){
	nume=nu;
	buget=bu;
    }
    private boolean cautaAngajat(Angajat a){
	for(int i=0; i<index; i++)
	    if(angajati[i]==a)
		return true;
	return false;
    }
    public boolean adaugaAngajat(Angajat a){
	if(index<30 && !(cautaAngajat(a)))
	    {
		angajati[index]=a;
		index++;
		return true;
	    }
	System.out.println("Nu s-a putut adauga angajatul");
	return false;
    }
    public String toString(){
	String rez=nume + ": ";
	for(int i=0; i<index; i++)
	    rez+=angajati[i];
	return rez;
    }
    private int sumaSalarii(){
	int s=0;
	for(int i=0; i<index; i++)
	    s+=angajati[i].getSalariu();
	return s;
    }
    public int platesteSalarii(){
	return buget - (this.sumaSalarii());
    }
}

class GestiuneFirme{
    public static void main(String[] args){
	Firma f=new Firma("Internet.srl", 50000);
	Angajat a1=new Angajat("Alexia", 7000);
	Angajat a2=new Angajat("Mihai", 5000);
	Angajat a3=new Angajat("Ionut", 6500);
	f.adaugaAngajat(a1);
	f.adaugaAngajat(a2);
	f.adaugaAngajat(a3);
	System.out.println(f);
	f.adaugaAngajat(a2);
	if(f.platesteSalarii()<0)
	    System.out.println("Buget lipsa: " + f.platesteSalarii());
	else
	  System.out.println("Buget ramas: " + f.platesteSalarii());  
    }
}
