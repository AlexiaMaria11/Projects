import java.util.Random;
import java.util.Date;

class CoordinateGenerator {
    private Random randomGenerator;
    public CoordinateGenerator() {
        Date now = new Date();
        long sec = now.getTime();
        randomGenerator = new Random(sec);
    }
    public int generateX() {
    int x = randomGenerator.nextInt(101);
    if(x < 5) {
        x = 0;
    } else if(x > 95) {
        x = 100;
        } else {
        x = randomGenerator.nextInt(99) + 1;
    }
    return x;
    }
    public int generateY() {
    int y = randomGenerator.nextInt(101);
    if(y < 5) {
        y = 0;
    } else if(y > 95) {
        y = 50;
    } else {
        y = randomGenerator.nextInt(49) + 1;
    }
    return y;
    }
}

class ExceptieOut extends RuntimeException{
    ExceptieOut(String msg){
        super(msg);
    }
}

class ExceptieGol extends RuntimeException{
    ExceptieGol(String msg){
        super(msg);
    }
}

class ExceptieCorner extends RuntimeException{
    ExceptieCorner(String msg){
        super(msg);
    }
}

class Minge{
    private int x, y;
    static CoordinateGenerator c = new CoordinateGenerator();
    public Minge(int x, int y){
        this.x=x;
        this.y=y;
    }
    public int getX(){
        return x;
    }
    public int getY(){
        return y;
    }
    public void suteaza() throws ExceptieOut, ExceptieGol, ExceptieCorner{
        x = c.generateX();
        y = c.generateY();
        if(y==0 || y==50){
            throw new ExceptieOut("Out.");
        }else{
            if((x==0 || x==100) && (y>=20 && y<=30)){
                throw new ExceptieGol("Gol.");
            }
            else if((x==0 || x==100) && ((0<y && y<20) || (30<y && y<50)))
            throw new ExceptieCorner("Corner");
        }
    }
}

class Joc{
    private String echipa1, echipa2;
    private int gol1=0, gol2=0, out=0, cornere=0;
    public Joc(String e1, String e2){
        echipa1=e1;
        echipa2=e2;
    }
    public String toString(){
        return echipa1 + " - " + echipa2 + ": " + gol1 + " - " + gol2 + " out-uri: " + out + " cornere: " + cornere;
    }
    public void simuleaza(){
        Minge m = new Minge(50,25);
        for(int i=0; i<1000; i++){
            try{
                m.suteaza();
            }catch(ExceptieOut e){
                m = new Minge(m.getX(), m.getY());
                out++;
              System.out.println("Out");
            }catch(ExceptieGol e){
                if(m.getX()>50) gol1++;
                else gol2++;
                m = new Minge(50,25);
              System.out.println("Gol");
            }catch(ExceptieCorner e){
                cornere++;
                if(m.getY()<20) m=new Minge(m.getX(),0);
                else m =new Minge(m.getX(),50);
               System.out.println("Corner");
            }finally{
            System.out.println(echipa1 + " - " + echipa2 + " : Mingea se afla la coordonatele (" + m.getX() + "," + m.getY() + ")");
            }
        }
    }
}

class Meci{
    public static void main(String args[]){
        Joc j1 = new Joc("Steaua", "Rapid");
        Joc j2 = new Joc("Steaua", "CRF Cluj");
        j1.simuleaza();
        j2.simuleaza();
        System.out.println(j1);
        System.out.println(j2);
    }
}
