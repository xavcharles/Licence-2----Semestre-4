package rental;
import java.util.*;
import rental.PriceCriterion;
import rental.BrandCriterion;
import rental.Criterion;
/**
 * @author : Eddy El Khatib
 */

/**
 * An InterCriterion performs the intersection of criterions. It is satisfied if each of its criterion is satisfied.
*/
public class InterCriterion implements Criterion {
    
    private List<Criterion> allCriterions;

    /** creates an InterCriterion with no criterion */
    public InterCriterion() {
        this.allCriterions = new ArrayList<Criterion>() ;
    }

    /** adds a new criterion
    * @param c the added criterion
    */
    public void addCriterion(Criterion c) {
        this.allCriterions.add(c);
    }

    /** This is satisfied if each of its criterion is satisfied.
     * @see Criterion#isSatisfiedBy(Vehicule) */
    public boolean isSatisfiedBy(Vehicle v) {
        for(int i=0;i<this.allCriterions.size();i++)
            if(!this.allCriterions.get(i).isSatisfiedBy(v)) return false;
        return true;
    }
}
