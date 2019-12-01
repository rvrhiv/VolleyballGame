#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class Player : public QObject, public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  Player();

  qreal getSpeedX() const;
  qreal getSpeedY() const;
  void setSpeedX(qreal speedX);
  void setSpeedY(qreal speedY);

public slots:
  void tick();
  void keyPress(QKeyEvent * event);
  void keyRelease(QKeyEvent * event);

private:
  std::size_t width_, height_;
  qreal speedX_, speedY_;
  bool isRight_, isLeft_, isUp_;

  void move();
  void colliding();
  void checkMaxSpeed();
  void checkCollisionWithScene();
};

#endif // PLAYER_H
