import java.util.*;

class WQIE extends RuntimeException{
    public WQIE(){
	super("WrongQualityIndicatorException");
    }
}

class WCCIE extends Exception{
    public WCCIE(){
	super("WrongComponentComplexityIndicatorException");
    }
}

interface Test{
    int getNumarTeste();
}

abstract class TestSimplu implements Test{
    protected String nume;
    protected int indicator;
    public TestSimplu(String nume, int indicator) throws WQIE{
	this.nume=nume;
	if(indicator<1 || indicator>10)
	    throw new WQIE();
	this.indicator = indicator;
    }
    public int getNumarTeste(){
	return 1;
    }
}

class IntegrationTest extends TestSimplu{
    public IntegrationTest(String nume, int indicator) throws WQIE{
	super(nume, indicator);
    }
    public String toString(){
	return "IntegrationTest(name=" + nume + ", qualityindicator=" + indicator + ")";
    }
}

class ComponentTest extends TestSimplu{
    private int complexitate;
    public ComponentTest(String nume, int indicator, int complexitate) throws WQIE, WCCIE{
	super(nume, indicator);
	if(complexitate<=0)
	    throw new WCCIE();
	this.complexitate = complexitate;
    }
    public String toString(){
	return "ComponentTest(name=" + nume + ", qualityindicator=" + indicator + ", component complexity indicator=" + complexitate + ")";
    }
}

class TestSuite implements Test{
    private List<Test> lista = new ArrayList<Test>();
    public TestSuite(List<Test> lis){
	lista=lis;
    }
    public int getNumarTeste(){
	int c=0;
	for(Test i:lista){
	    c+=i.getNumarTeste();
	}
	return c;
    }
    public boolean addNewIntegrationTest(String nume, int indicator){
	IntegrationTest i;
	try{
	    i = new IntegrationTest(nume, indicator);
	}catch(WQIE e){
	    return false;
	}
	lista.add(i);
	return true;
    }
    public boolean addNewComponentTest(String nume, int indicator, int complexity) throws WCCIE {
	ComponentTest c;
	try{
	    c = new ComponentTest(nume, indicator, complexity);
	} catch(WQIE e){
	    return false;
	}
	lista.add(c);
	return true;
    }
    public String toString(){
	String s="TestSuite (";
	for(Test i:lista)
	    s+=i+" ";
	s+=")";
	return s;
    }
}

class Teste{
    public static void main(String args[]){
	TestSuite t1 = new TestSuite(new ArrayList<Test>());
	t1.addNewIntegrationTest("i1", 5);
	t1.addNewIntegrationTest("i2", 4);
	try{
	    t1.addNewComponentTest("c1", 1, 5);
	}catch(WCCIE e){
	    System.out.println("a aparut o exceptie");
	}
	try{
	    t1.addNewComponentTest("c2", 0, 8);
	}catch(WCCIE e){
	    System.out.println("a aparut o exceptie");
	}
	try{
	     t1.addNewComponentTest("c3", 1, 0);
	}catch(WCCIE e){
	    System.out.println("a aparut o exceptie");
	}
	try{
	     t1.addNewComponentTest("c4", 3, 8);
	}catch(WCCIE e){
	    System.out.println("a aparut o exceptie");
	}
	System.out.println(t1);
    }
}
