import java.util.*;

interface Propozitie{
    public boolean determinaValoareAdevar(ArrayList<Boolean> valori);
}

class PropozitieAtomica implements Propozitie{
    private int index;
    public PropozitieAtomica(int in){
	index=in;
    }
    public boolean determinaValoareAdevar(ArrayList<Boolean> valori){
	int c=0;
	for(Boolean v:valori){
	    if(c==index)
		return v;
	    c++;
	}
	return false;
    }
    public String toString(){
	return "Atom"+index;
    }
}

class Negatie implements Propozitie{
    private Propozitie neg;
    public Negatie(Propozitie p){
	neg=p;
    }
    public boolean determinaValoareAdevar(ArrayList<Boolean> valori){
	boolean b = neg.determinaValoareAdevar(valori);
	if(b)
	    return false;
	else
	    return true;
    }
    public String toString(){
	return "!" + neg;
    }
}

class SiMultiplu implements Propozitie{
    private ArrayList<Propozitie> prop;
    public SiMultiplu(ArrayList<Propozitie> p){
	prop=p;
    }
    public String toString(){
	String s="(";
	Iterator<Propozitie> it = prop.iterator();
	while(it.hasNext()){
	    s+=it.next();
	    if(it.hasNext())
		s+=" & ";
	}
	s+=")";
	return s;
    }
    public boolean determinaValoareAdevar(ArrayList<Boolean> valori) throws IndexOutOfBoundsException{
	int c1=0, c2=0;
	for(Propozitie p1:prop)
	    c1++;
	for(Boolean b:valori)
	    c2++;
	if(c1!=c2)
	    throw new IndexOutOfBoundsException();
	for(Propozitie p:prop){
	    if(p.determinaValoareAdevar(valori)==false)
		return false;
	}
	return true;
    }
}

class Main{
    public static void main(String args[]){
    PropozitieAtomica p1,p2,p3,p4;
    p1=new PropozitieAtomica(0);
    p2=new PropozitieAtomica(1);
    p3=new PropozitieAtomica(2);
    p4=new PropozitieAtomica(3);
    Negatie n1, n2;
    n1=new Negatie(p2);
    n2=new Negatie(p4);
    ArrayList<Propozitie> prop = new ArrayList<Propozitie>();
    prop.add(p1);
    prop.add(n1);
    prop.add(p3);
    prop.add(n2);
    ArrayList<Boolean> val1 = new ArrayList<Boolean>();
    val1.add(true);
    val1.add(false);
    val1.add(true);
    SiMultiplu s = new SiMultiplu(prop);
    System.out.println(s);
    try{
	s.determinaValoareAdevar(val1);
	System.out.println(s.determinaValoareAdevar(val1));
    } catch(IndexOutOfBoundsException e){
	System.out.println("Exceptie");
    }
    ArrayList<Boolean> val2 = new ArrayList<Boolean>();
    val2.add(true);
    val2.add(false);
    val2.add(true);
    val2.add(false);
    try{
	s.determinaValoareAdevar(val2);
	System.out.println(s.determinaValoareAdevar(val2));
    } catch(IndexOutOfBoundsException e){
	System.out.println("Exceptie");
    }
    }
}
