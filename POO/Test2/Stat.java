import java.util.*;

abstract class Statistica{
    protected String jurnal="";
    abstract void calculeaza(List<String> siruri);
    public String toString(){
	return jurnal + "\n";
    }
}

class StatisticaNumarAparitii extends Statistica{
    private List<String> cautate = new ArrayList<String>();
    public StatisticaNumarAparitii(List<String> c){
	cautate = c;
    }
    public void calculeaza(List<String> siruri){
	int c=0;
	jurnal="";
	for(String i: siruri){
	    for(String j:cautate)
		if(i.equals(j)) c++;
	}
	jurnal+="In secventa {";
	Iterator<String> it1 = siruri.iterator();
	while(it1.hasNext()){
	    jurnal+=it1.next();
	    if(it1.hasNext()) jurnal+=", ";
	}
	jurnal+="} apar " + c + " siruri din secventa {";
	Iterator<String> it2 = cautate.iterator();
	while(it2.hasNext()){
	    jurnal+=it2.next();
	    if(it2.hasNext()) jurnal+=", ";
	}
	jurnal+="}";
    }
}

class StatisticaNumeraleNonReale extends Statistica{
    public void calculeaza(List<String> siruri){
	jurnal = "";
	int c=0;
	for(String i:siruri){
	    try{
		Double.parseDouble(i);
	    }catch(NumberFormatException e){
		c++;
	    }
	}
	jurnal+="In secventa {";
	Iterator<String> it = siruri.iterator();
	while(it.hasNext()){
	    jurnal+=it.next();
	    if(it.hasNext()) jurnal+=", ";
	}
	jurnal+="} avem " + c + " siruri ce nu sunt numere reale";
    }
}

class Executor{
    private List<Statistica> statistici = new ArrayList<Statistica>();
    public Executor(List<Statistica> st){
	statistici = st;
    }
    public void executa(List<String> siruri){
	for(Statistica i:statistici){
	    i.calculeaza((List<String>)siruri);
	    System.out.print(i);
	}
    }
}

class Stat{
    public static void main(String args[]){
	List<String> caut = new ArrayList<String>();
	caut.add("mere");
	caut.add("pere");
	caut.add("banane");
	Statistica s1 = new StatisticaNumarAparitii(caut);
	Statistica s2 = new StatisticaNumeraleNonReale();
	List<Statistica> stats = new ArrayList<Statistica>();
	stats.add(s1);
	stats.add(s2);
	Executor e = new Executor(stats);
	List<String> secv1 = new ArrayList<String>();
	secv1.add("Ana"); secv1.add("are"); secv1.add("mere");
	List<String>secv2 = new ArrayList<String>();
	secv2.add("Maria"); secv2.add("are"); secv2.add("32");
	e.executa(secv1);
	e.executa(secv2);
    }
}
