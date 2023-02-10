import java.util.LinkedList;
public class Dealer{
  private Deck m_deck;
  //default
  public Dealer(){
    m_deck = new Deck();
  }
  //deals method
  public LinkedList<Card> deals (int n){
    LinkedList<Card> dealtCards= new LinkedList<>();
    for (int i =0;i<n;++i){
      dealtCards.add(m_deck.deal());
    }
    return dealtCards;
  }
  public String toString(){
    return m_deck.toString();
  }
  // size method
  public int size(){
    return m_deck.size();
  }
}
