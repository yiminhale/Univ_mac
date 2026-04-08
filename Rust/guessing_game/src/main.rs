use std::io;//prelude
use rand::Rng;

fn main() {
    println!("Guess the number!");//단순 출력
    let secret_number=rand::rng().random_range(1..=100);
    println!("The secret number is: {secret_number}");
    println!("Plz input your guess.");//단순 출력
    let mut guess = String::new();//변수 선언. 변수 선언시 let 사용. e.g. let apples = 5;
    //Rust에서는 기본적으로 변수가 불변임. 가변으로 만드려면 mutable 즉, mut라고 변수명 앞에 추가.
    io::stdin()//:: 는 연관함수. 즉, 좌측이 상단집합이고 우측이 부분집합의 함수를 의미하는듯.
        .read_line(&mut guess)
        .expect("Failed to read line");

    println!("You guessed: {guess}");
}
