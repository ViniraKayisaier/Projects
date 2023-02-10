import java.util.Random;
import java.util.LinkedList;

public class Player{
  private int m_NumofPlayer;
  private static int m_RoundofGame = 1;
  private static int m_PrevPlayer = 1;
  private static Card m_PrevPlayerCard;
  private LinkedList<Card>m_Hand;
  private boolean m_StoleSpoon;
  private boolean m_GameOver;

  //taketurn method
  public void takeTurn (Dealer dealer){
  if(m_NumofPlayer == 1){
    m_PrevPlayerCard = dealer.deals(1).get(0);
      //Sysytem.out.println(m_PrevPlayerCard.toString());
  }
     System.out.println("The number of player is:"+m_NumofPlayer);

    for (int i = 0;i < m_Hand.size();i++){
       System.out.println(m_Hand.get(i));
       //System.out.println(m_Hand.get(i).toString());
     }

    for (int j = 0; j < m_Hand.size()-1;j++){
      if (m_RoundofGame == 1){
        m_Hand.add(m_Hand.get(j));
        m_Hand.remove(j);
        for(int k = 1;k < m_Hand.size();k++){
          if(m_Hand.get(j).equal(m_Hand.get(k))&& j != k){
            m_Hand.add(m_Hand.get(k));
            m_Hand.remove(k);
          }
        }
      }
    }

    //check matchingcards with the cards the player chose
    for(int i = 0;i < m_Hand.size();i++){
      if(m_Hand.get(i).equal(m_PrevPlayerCard)){
        m_Hand.add(m_Hand.get(i));
        m_Hand.remove(i);
      }
    }
    for (int j = 0;j < m_Hand.size();j++){
      //System.out.println(m_Hand.get(j).toString());
     }
    System.out.println();
    if (m_NumofPlayer == 5){
      m_PrevPlayerCard = null;
      m_RoundofGame++;
      System.out.println(m_RoundofGame);
    }
    System.out.println(m_PrevPlayerCard);
  }

  // StealSpoon method
  public Player(Dealer deal){
    m_StoleSpoon = true;
    m_NumofPlayer = m_PrevPlayer;
    m_Hand = new LinkedList<>();
    m_Hand = deal.deals(4);
    m_PrevPlayer++;
    m_GameOver = true;
    /*if statement including if first card in hand matching all 2nd, 3rd, and 4th card.
    *this means that all the cards in player's hand matches, which satifies the condition of stealing spoon.
    *if the statement is true, then m_StoleSpoon would be true
    *The for the rest the player noticing the spoon, it would be Random, 4 out of 5 player would notice spoon missing
    *so if player is in the game and m_StoleSpoon is not true, then they can steal the spoon.
    */
    /* In the game.java, the spoon method checks if there is spoon remaining still. In boolean m_GameOver, once
    * int Spoons in Game.java = 0, then m_GameOver would = true.
    */
  }
}
