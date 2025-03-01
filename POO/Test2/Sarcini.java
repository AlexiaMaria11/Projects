import java.util.*;

abstract class Task{
    protected String nume;
    public Task(String nume){
	this.nume=nume;
    }
    abstract boolean execute(double secunde);
}

class SimpleTask extends Task{
    private double necesar, ramas;
    public SimpleTask(String nume, double n){
	super(nume);
	necesar=n;
	ramas=necesar;
    }
    public boolean execute(double secunde){
	if(ramas>0){
	    ramas = ramas-secunde;
	    if(ramas>0)
		return false;
	    else
		return true;
	}
	return true;
    }
    public String toString(){
	return "Nume: " + nume + ", Timp: " + ramas;
    }
}

class ComposedTask extends Task{
    private List<SimpleTask> lista = new ArrayList<SimpleTask>();
    public ComposedTask(String nume, ArrayList<SimpleTask> a){
	super(nume);
	lista = a;
    }
    public boolean execute(double secunde){
	Iterator<SimpleTask> it = lista.iterator();
	boolean ok = true;
	while(it.hasNext()){
	    if(!it.next().execute(secunde/(lista.size())))
		ok=false;
	}
	return ok;
    }
    public String toString(){
	String s="Nume: " + nume + ", Continut: (";
	Iterator<SimpleTask> it = lista.iterator();
	int k=0;
	while(it.hasNext()){
	    k++;
	    s+="SimpleTask" + k + "-" + it.next();
	    if(it.hasNext())s+=", ";
	}
	s+=")";
	return s;
    }
}

class Procesor{
    private List<Task> li = new ArrayList<Task>();
    public Procesor(ArrayList<Task> a){
	li=a;
    }
    public void finishAllTasks(){
	Iterator<Task> it = li.iterator();
	while(it.hasNext()){
	    Task t = it.next();
	    while(!t.execute(5.0));
	}
    }
    public String toString(){
	String s="Procesor: ";
	Iterator<Task> it = li.iterator();
	while(it.hasNext()){
	    s+="Task1: " + it.next();
	    if(it.hasNext()) s+=", ";
	}
	return s;
    }
}

class Sarcini{
    public static void main(String args[]){
	List<Task> lista = new ArrayList<Task>();
	List<SimpleTask> simple = new ArrayList<SimpleTask>();
	simple.add(new SimpleTask("S1", 5));
	simple.add(new SimpleTask("S2", 10));
	lista.add(new ComposedTask("Compus", (ArrayList<SimpleTask>)simple));
	Procesor p = new Procesor((ArrayList<Task>)lista);
	System.out.println(p);
	p.finishAllTasks();
	System.out.println(p);
    }
}
