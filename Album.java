import java.util.ArrayList;

public class Album extends ContentCollection{
  protected ArrayList<Songs>m_album;

  public Album(){
    m_album = new ArrayList<Songs>();
  }
  public void playAlbum(){
    for (int i = 0; i < m_album.size();i++){
    m_album.get(i).Stream();
    }
  }
}
