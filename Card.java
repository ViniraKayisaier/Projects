public class Card{
  private int m_rank;
  private int m_suit;

  public static final int Hearts = 0;
  public static final int Spades = 1;
  public static final int Clubs = 2;
  public static final int diamonds = 3;

  public static final int Jack = 11;
  public static final int Queen = 12;
  public static final int King = 13;
  public static final int Ace = 14;
  //default
  public Card(){
    m_rank = 14;  // ace
    m_suit = 1; // spades
  }
  //overload
  public Card(int r, int s){
    m_rank = r;
    m_suit = s;
  }
  //copy constructor
  public Card(Card CardToCopy){
    this.m_rank = CardToCopy.m_rank;
    this.m_suit = CardToCopy.m_suit;
  }
  // accessors
  public int getRank(){
    return m_rank;
  }
  public int getSuit(){
    return m_suit;
  }
  // mutators
  public void setRank (int newRank){
    m_rank = newRank;
  }
  public void setSuit (int newSuit){
    m_suit = newSuit;
  }
  //ToString
  public String toString(){
    String c = "";
    if (m_rank < 11){
      c +=  m_rank;
    } else if (m_rank == 11){
      c += "Jack";
    } else if (m_rank == 12){
      c += "Queen";
    } else if (m_rank == 13){
      c += "King";
    } else if (m_rank == 14){
      c += "Ace";
    }
    c += " of ";
    if(m_suit == 0){
      c += "Hearts";
    } else if (m_suit == 1){
      c += "Spades";
    } else if (m_suit == 2){
      c += "Clubs";
    } else if (m_suit == 3){
      c += "Diamonds";
    }
    return c;
  }

 // equal method
  public boolean equal(Object o){
    if (!(o instanceof Card)){
      return false;
  }
    Card c = (Card) o;
      return (this.m_rank==c.m_rank);
  }

}
