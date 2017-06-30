package rental;
import rental.RentalAgency;
import java.util.*;
/**
 * @author : Mohand Outioua
 */
/** a rental vehicle agency, client can rent one vehicle at a time */
public class SuspiciousRentalAgency extends RentalAgency {
	public float rentVehicule(Client client, Vehicle v) throws NoSuchElementException, IllegalStateException {
		float tmp = super.rentVehicule(client,v);
		return (client.getAge() < 25)?(tmp + ((tmp * 10)/100)):tmp;
	}
}

