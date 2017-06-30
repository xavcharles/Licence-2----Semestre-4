package goosegame ;

/**
 * @author : Mohand Outioua
 */

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;

public class WaitCellTest {
	private Cell waitCell ; 

	@Before
	public void before() {
		this.waitCell = new WaitCell(19,2) ;	
	}
	@Test
	public void waitCelltest() {
		assertNotNull(this.waitCell) ;	
	}
	@Test
	public void canBeLefttest() {
		assertFalse(this.waitCell.canBeLeft());
		assertFalse(this.waitCell.canBeLeft());
		assertTrue(this.waitCell.canBeLeft());
	}
	@Test
	public void getIndextest() {
		assertEquals(this.waitCell.getIndex(),19) ;	
	}
	@Test
	public void handleMovetest() {
		assertEquals(this.waitCell.getIndex(),19) ;	
	}
	@Test
	public void getPlayertest() {
		Player p1 = new Player("Outioua") ;

		this.waitCell.welcomePlayer(p1) ;
		assertEquals(this.waitCell.getPlayer().toString(),"Outioua") ;
	}
	@Test
	public void isBusytest() {
		Player p1 = new Player("Elkhatib") ;
		assertFalse(this.waitCell.isBusy()) ;
		this.waitCell.welcomePlayer(p1) ;
		assertTrue(this.waitCell.isBusy()) ;
	}
	

	
    // ---Pour permettre l'execution des tests ----------------------
    public static junit.framework.Test suite() {
		return new junit.framework.JUnit4TestAdapter(goosegame.WaitCellTest.class);
    }
}
