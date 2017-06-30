package trie;

import static org.junit.Assert.*;

import org.junit.Test;

public class CompactTrieTest {

	@Test
	public void addContainsTest() {
		CompactTrie someTrie = new CompactTrie();
		someTrie.add("citron");
		someTrie.add("banane");
		someTrie.add("citronnier");
		someTrie.add("pomme");
		someTrie.add("poire");
		someTrie.add("ci");
		assertTrue(someTrie.contains("citron"));
		assertTrue(someTrie.contains("banane"));
		assertTrue(someTrie.contains("citronnier"));
		assertFalse(someTrie.contains("tronnier"));
		assertFalse(someTrie.contains("po"));
		assertTrue(someTrie.contains("ci"));
		assertTrue(someTrie.contains("pomme"));
		assertTrue(someTrie.contains("poire"));
	}

	 // ---Pour permettre l'execution des tests ----------------------
    public static junit.framework.Test suite() {
	return new junit.framework.JUnit4TestAdapter(trie.CompactTrieTest.class);
    }
}