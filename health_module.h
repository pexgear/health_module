template <typename T>
class HealthModule
{
    protected:
		HealthModule() {}

		HealthModule(T _max_health)
		{
			init(_max_health);
		}

		~HealthModule() {}

	public:
		virtual void init(T _max_health)
		{
			max_health = _max_health;
			set_health_unckecked(max_health);
		}

		virtual void reinit()
		{
			set_health_unckecked(max_health);
		}

		virtual void set_health(T _health)
		{
			if (_health < 0.0)
			{
				_health = 0.0;
			}

			if (_health > max_health)
			{
				_health = max_health;
			}
			set_health_unckecked(_health);
		}

		virtual T get_health() const
		{
			return health;
		}

		virtual T get_max_health() const
		{
			return max_health;
		}

		virtual void set_health_unckecked(T _health)
		{
			health = _health;
		}

		virtual bool is_max_health_valid()
		{
			return max_health > 0.0;
		}		

	private:
		T max_health = 0.0;
		T health = 0.0;
};