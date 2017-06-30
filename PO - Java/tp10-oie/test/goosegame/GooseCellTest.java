package goosegame ;

/**
 * @author : Mohand Outioua
 */

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;


public class GooseCellTest {
	private Cell gooseCell ;

	@Before
	public void before() {
		this.gooseCell = new GooseCell(45) ;	
	}
	@Test
	public void testnormalcell() {
		assertNotNull(this.gooseCell) ;	
	}
	@Test
	public void testcanBeLeft() {
		assertTrue(this.gooseCell.canBeLeft()) ;	
	}
	@Test
	public void testgetindex() {
		assertEquals(this.gooseCell.getIndex(),45) ;
	}
	@Test	
	public void testhandleMove() {
		assertEquals(this.gooseCell.handleMove(4),49) ;
	}
	@Test
	public void testGetPlayer() {
		Player p1 = new Player("Outioua") ;
		this.gooseCell.welcomePlayer(p1) ;
		assertEquals(this.gooseCell.getPlayer().toString(),"Outioua") ;	
	}
	@Test
	public void testIsBusy() {
		Player p1 = new Player("Elkhatib") ;
		assertFalse(this.gooseCell.isBusy()) ;
		this.gooseCell.welcomePlayer(p1) ;
		assertTrue(this.gooseCell.isBusy()) ;

	}


    // ---Pour permettre l'execution des tests ----------------------
    public static junit.framework.Test suite() {
		return new junit.framework.JUnit4TestAdapter(goosegame.GooseCellTest.class);
    }
}
