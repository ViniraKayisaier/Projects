import java.util.Random;
public class Deck{
    private LinkedList <Card> m_cards;
    //default
    public Deck(){
      m_cards = new LinkedList<>();
      for(int i = 0; i<=3; ++i){
        for(int j =2; j<= 14;++j){
          Card newCard = new Card(j,i);
          m_cards.add(newCard);
        }
      }
    }
    //copy constructor
    public Deck(Deck d){
      m_cards = new LinkedList<>();
      for(Card c: d.m_cards){
      this.m_cards.add(new Card(c));
      }
    }

    //toString
    public String toString(){
      String d = "";
      for(int i = 0; i< m_cards.size();++i){
      d += m_cards.get(i).toString() + "\n";
      }
      return d;
    }
    //Size method
    public int size(){
      int size = m_cards.size();
      return size;
    }
    // method deal
    public Card deal(){
      Random r = new Random();
      int position = r.nextInt(m_cards.size());
      Card rc = m_cards.get(position);
      m_cards.remove(position);
      return rc;
    }
}
