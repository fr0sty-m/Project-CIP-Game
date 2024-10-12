#ifndef CBQ_FRAMEWORK_APPLICATION_HPP
#define CBQ_FRAMEWORK_APPLICATION_HPP

namespace cbq {

class Application {
public:
  Application() = default;

  virtual void Begin() = 0;

  virtual void EarlyUpdate(float deltaTime) {};
  virtual void Update(float deltaTime) = 0;
  virtual void LateUpdate(float deltaTime) {};

  virtual void EarlyRender() {};
  virtual void Render() = 0;
  virtual void LateRender() {};
};

} // namespace cbq

#endif // !CBQ_FRAMEWORK_APPLICATION_HPP
