public abstract class Account{
  protected int m_ID;
  private static int NextID = 507507;
  //default constructor
  public Account(){
    m_ID = NextID;
    NextID++;
  }
  //fully specified overload
  public Account(int i){
    m_ID = i;
  }
  //copy contructor
  public Account(Account i){
    this.m_ID = i.m_ID;
  }
  // accessors
  public int getID(){
    return m_ID;
  }
  //toString
  public String toString(){
    String s = "";
    s += "\nThe ID is:" + m_ID;
    return s;
  }


}
