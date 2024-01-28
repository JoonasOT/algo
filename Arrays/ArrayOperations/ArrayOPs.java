import java.util.ArrayList;
import java.util.Collections;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class ArrayOPs {
    public static void main(String[] args) {

    }
    public static <T> ArrayList<Integer> get_frequency(ArrayList<T> arr, Stream<T> possible_elements) {
        return new ArrayList<>(possible_elements.mapToInt(elem -> Collections.frequency(arr, elem)).boxed().toList());
    }
}
